#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
int Ai=0;
float getVPP();
const int sensorIn = 34;
int mVperAmp = 66; // use 185 for 5A Module and 100 for 20A Module
 int ampcount=0;
int autostart=0;
double sum=0;
int aram=0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

int count=0;
int sendpin=0;
int repin=2;
int repin2=4;
int repin3=5;
int repin4=18;

const char* ssid     = "iptime1";
const char* password = "50255025";

const char* serverName = "http://leejiseok.iptime.org:50/input.php";
const String endpoint = "http://leejiseok.iptime.org:50/open.php";
String line = ""; 

void setup() {
  Serial.begin(115200);
  pinMode(repin,OUTPUT);
  pinMode(repin2,OUTPUT);
  pinMode(repin3,OUTPUT);
  pinMode(repin4,OUTPUT);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
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
  Voltage = getVPP();
 VRMS = (Voltage/2.0) *0.707;
 AmpsRMS = (VRMS * 1000)/mVperAmp;
 //Serial.print(AmpsRMS);
 //Serial.println(" Amps RMS");
  //Check WiFi connection status
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
 
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    String httpRequestData;
    String httpRequestData2;
    http.begin(client, serverName);
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    if(sendpin!=1){
    httpRequestData = "apikey=" + String((AmpsRMS*220.0)/100.0)+"&aram="+String(aram);
    }
    else{
      sendpin=0;
      httpRequestData = "apikey=" + String((AmpsRMS*220.0)/100.0)+"&LED="+String(sendpin)+"&aram="+String(aram);
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
 
void parsing() {
  String pin,pin2,pin3,pin4,pin5;  
  int tm_start2= line.indexOf(F("<h2>")); // "<tm>"문자가 시작되는 인덱스 값('<'의 인덱스)을 반환한다. 
  int  tm_end2= line.indexOf(F("</h2>"));
  
  int tm_start3= line.indexOf(F("<h3>")); // "<tm>"문자가 시작되는 인덱스 값('<'의 인덱스)을 반환한다. 
  int  tm_end3= line.indexOf(F("</h3>"));
  
  int tm_start4= line.indexOf(F("<h4>")); // "<tm>"문자가 시작되는 인덱스 값('<'의 인덱스)을 반환한다. 
  int  tm_end4= line.indexOf(F("</h4>"));

   int tm_start5= line.indexOf(F("<h5>")); // "<tm>"문자가 시작되는 인덱스 값('<'의 인덱스)을 반환한다. 
  int  tm_end5= line.indexOf(F("</h5>"));
  
   int tm_start6= line.indexOf(F("<AI>")); // "<tm>"문자가 시작되는 인덱스 값('<'의 인덱스)을 반환한다. 
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
