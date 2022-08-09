float getVPP();
const int sensorIn = 34;
int mVperAmp = 66; // use 185 for 5A Module and 100 for 20A Module
 
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;
int ampcount=0;
int autostart=0;
double sum=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sum=1;
}

void loop() {
  // put your main code here, to run repeatedly:
 Voltage = getVPP();
 VRMS = (Voltage/2.0) *0.707;             // RMS값 70.7%
 AmpsRMS = (VRMS * 1000)/mVperAmp;        // mA 단위 맞춰줌
 Serial.print(String(AmpsRMS));
 Serial.print(",");
 if(ampcount==30){
   if((AmpsRMS<=sum+1.5&&AmpsRMS>=sum)||(AmpsRMS<=sum&&AmpsRMS>sum-1.5)){
    autostart++;
   }
   else{
    autostart=0;
    sum=AmpsRMS;
    ampcount=0;
    }
 }
 else if(autostart==0){
  sum=(AmpsRMS+sum)/2.0;
  ampcount++;
 }
 Serial.println(String(sum));
 if(autostart>=20){
  Serial.println("현재 반응이 없습니다");
 }
 
}
float getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0.8;          // store max value here
  int minValue = 4069;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 2000) // 1초동안 값을 모아서 AC 전류의 최고점, 최저점을 찾아 평균치를 구함
   {
      
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue&&0!=readValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;        // 5V 분해능, 아날로그핀의 분해능 1024
      
   return result;
 }
