#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
int Ai=0;
/*
  전력 측정센서를 위한 변수
*/
float getVPP();

const int sensorIn = 34;
int mVperAmp = 66; // use 185 for 5A Module and 100 for 20A Module
 int ampcount=0;
int autostart=0;

float getVPP2();

const int sensorIn2 = 35;
int mVperAmp2 = 66; // use 185 for 5A Module and 100 for 20A Module
int ampcount2=0;
int autostart2=0;

/*
  현재 멀티탭 상태를 저장할 변수 
*/
double sum=0;
int aram=0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

double Voltage2 = 0;
double VRMS2 = 0;
double AmpsRMS2 = 0;

int count=0;
int sendpin=0;
int repin=2;
int repin2=4;
int repin3=5;
int repin4=18;

// 와이파이를 연결한다 
const char* ssid     = "jiseok";
const char* password = "12345678";

// 연결 서버 주소를 입력한다 
const char* serverName = "http://leejiseok.iptime.org:50/input.php";
const String endpoint = "http://leejiseok.iptime.org:50/open.php";

String line = ""; 

void setup() {
  Serial.begin(115200);
  //핀 지정
  pinMode(repin,OUTPUT);
  pinMode(repin2,OUTPUT);
  pinMode(repin3,OUTPUT);
  pinMode(repin4,OUTPUT);
  
  // 와이파이를 연결한다 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  // 연결상태를 확인한다 
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // 처음 웹에서 저장되어 있는 멀티탭 상태를 가져온다 
  get_weather();
}

void get_weather() {
  if ((WiFi.status() == WL_CONNECTED)) {
    //Serial.println("Starting connection to server...");
    HTTPClient http;
    http.begin(endpoint);       
    int httpCode = http.GET();  
    if (httpCode > 0) {
      line = http.getString();
    }
    else {
      Serial.println("Error on HTTP request");
    }

    parsing();
    http.end(); //Free the resources
  }
}

void loop() {
  // 전력 측정 데이터를 처리한다 
  Voltage = getVPP();
  VRMS = (Voltage/2.0) *0.707;
  AmpsRMS = (VRMS * 1000)/mVperAmp;

  Voltage2 = getVPP2();
  VRMS2 = (Voltage2/2.0) *0.707;
  AmpsRMS2 = (VRMS2 * 1000)/mVperAmp2;
  
  /*
   일정 횟수 동안 전력 측정이 데기전력으로 측정이 되면 전기를 차단 한다 
  */ 
  if(Ai==1){
    if(AmpsRMS<=4.2){
      count++;
    }
    else{
      count=0;
    }
    if(count==7){
      digitalWrite(repin,1);
      sendpin=1;
      count=0;
    }
  }

  Serial.print(String(AmpsRMS));
  Serial.print(",");

  if(ampcount>=30){
    if((AmpsRMS<=sum+1.5&&AmpsRMS>=sum)||(AmpsRMS<=sum&&AmpsRMS>sum-1.5)){
      autostart++;
      ampcount=30;
    }
    else{
      if(ampcount==34){
        autostart=0;
        sum=AmpsRMS;
        ampcount=0;
      }
      else{
        ampcount++;
      }
    }
  }
  else if(autostart==0){
    sum=(AmpsRMS+sum)/2.0;
    ampcount++;
    aram=0;
  }
  Serial.println(String(sum));
  if(autostart>=20){
    Serial.println("현재 반응이 없습니다");
    aram=1;
  }

  if(AmpsRMS<=4.2){
    AmpsRMS=0;
  }
  if(AmpsRMS2<=4.2){
    AmpsRMS2=0;
  }
  // 웹에 데이터를 전송한다 
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    String httpRequestData;
    String httpRequestData2;
    http.begin(client, serverName);
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    if(sendpin!=1){
    httpRequestData = "apikey=" + String((AmpsRMS*220.0)/100.0)+"&apikey2=" + String((AmpsRMS2*220.0)/100.0)+"&aram="+String(aram);
    }
    else{
      sendpin=0;
      httpRequestData = "apikey=" + String((AmpsRMS*220.0)/100.0)+"&apikey2=" + String((AmpsRMS2*220.0)/100.0)+"&LED="+String(sendpin)+"&aram="+String(aram);
    }
    //Serial.print("httpRequestData: ");
    //Serial.println(httpRequestData);
    
    int httpResponseCode = http.POST(httpRequestData);
    
    if (httpResponseCode>0) {
      //Serial.print("HTTP Response code: ");
      //Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  get_weather();  
  delay(2000);
}

// 전력 측정 센서 데이터를 가져온다
float getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 4096;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) // 1초동안 값을 모아서 AC 전류의 최고점, 최저점을 찾아 평균치를 구함
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;        // 5V 분해능, 아날로그핀의 분해능 1024
      
   return result;
 }

 float getVPP2()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 4096;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) // 1초동안 값을 모아서 AC 전류의 최고점, 최저점을 찾아 평균치를 구함
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;        // 5V 분해능, 아날로그핀의 분해능 1024
      
   return result;
 }
 
void parsing() {
  /*
   웹에서 가져온 데이터를 처리하여 불을 on/off한다
  */
  String pin,pin2,pin3,pin4,pin5;  
  // 문자열을 처리한다 
  int tm_start2= line.indexOf(F("<h2>")); 
  int  tm_end2= line.indexOf(F("</h2>"));
  
  int tm_start3= line.indexOf(F("<h3>"));  
  int  tm_end3= line.indexOf(F("</h3>"));
  
  int tm_start4= line.indexOf(F("<h4>")); 
  int  tm_end4= line.indexOf(F("</h4>"));

   int tm_start5= line.indexOf(F("<h5>"));
  int  tm_end5= line.indexOf(F("</h5>"));
  
   int tm_start6= line.indexOf(F("<AI>"));
  int  tm_end6= line.indexOf(F("</AI>"));
  
  pin2 = line.substring(tm_start2 + 4, tm_end2);  
  pin3 = line.substring(tm_start3 + 4, tm_end3);  
  pin4 = line.substring(tm_start4 + 4, tm_end4);  
  pin5 = line.substring(tm_start5 + 4, tm_end5);  
  pin = line.substring(tm_start6 + 4, tm_end6);
  
  int myInt2 = pin2.toInt();
  int myInt3 = pin3.toInt();
  int myInt4 = pin4.toInt();
  int myInt5 = pin5.toInt();
  int myInt = pin.toInt();
  
  // 데이터에 맞게 릴레이를 on/off한다 
  if(myInt==1){
    Ai=1;
    Serial.println("ON1");
  }
  else if(myInt==0){
    Ai=0;
    count=0;
    //Serial.println("OFF");
  }
  
  if(myInt2==1){
    digitalWrite(repin,0);
    //Serial.println("ON1");
  }
  else if(myInt2==0){
    digitalWrite(repin,1);
    //Serial.println("OFF");
  }
  
  if(myInt3==1){
    digitalWrite(repin2,0);
    //Serial.println("ON1");
  }
  else if(myInt3==0){
    digitalWrite(repin2,1);
    //Serial.println("OFF");
  }
  
  if(myInt4==1){
    digitalWrite(repin3,0);
    //Serial.println("ON1");
  }
  else if(myInt4==0){
    digitalWrite(repin3,1);
    //Serial.println("OFF");
  }
  
  if(myInt5==1){
    digitalWrite(repin4,0);
    //Serial.println("ON1");
  }
  else if(myInt5==0){
    digitalWrite(repin4,1);
    //Serial.println("OFF");
  }
}
