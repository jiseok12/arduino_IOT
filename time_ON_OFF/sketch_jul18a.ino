#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// WiFi network
const char* ssid     = "iptime1";
const char* password = "50255025";

ESP8266WebServer server ( 80 );

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600*9, 60000);
String hours="";
String minuts="";

String hours2="";
String minuts2="";

char htmlResponse[9000];
void handleRoot() {
  snprintf ( htmlResponse, 9000,""); 
   server.send ( 200, "text/html", htmlResponse );  
}
void handleSave() {
  if (server.arg("hh")!= ""){
    Serial.println("Hours: " + server.arg("hh"));
    hours=server.arg("hh");
  }
  if(server.arg("mm")!= ""){
    Serial.println("Minutes: " + server.arg("mm"));
    minuts=server.arg("mm");
  }
  if (server.arg("hh2")!= ""){
    Serial.println("Hours: " + server.arg("hh2"));
    hours2=server.arg("hh2");
  }
  if (server.arg("mm2")!= ""){
    Serial.println("Minutes: " + server.arg("mm2"));
    minuts2=server.arg("mm2");
  }
  
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");  
}
void ONLED1(){
  digitalWrite(D1,0);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void OFFLED1(){
  digitalWrite(D1,1);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void ONLED2(){
  digitalWrite(D2,0);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void OFFLED2(){
  digitalWrite(D2,1);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void ONLED3(){
  digitalWrite(D3,0);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void OFFLED3(){
  digitalWrite(D3,1);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void ONLED4(){
  digitalWrite(D4,0);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void OFFLED4(){
  digitalWrite(D4,1);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void ONLED(){
  digitalWrite(D1,0);
  digitalWrite(D2,0);
  digitalWrite(D3,0);
  digitalWrite(D4,0);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void OFFLED(){
  digitalWrite(D1,1);
  digitalWrite(D2,1);
  digitalWrite(D3,1);
  digitalWrite(D4,1);
  server.send ( 200, "text/html", "<script>location.href='http://192.168.0.2:5500/';</script>");
}
void setup() {
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
digitalWrite(D1,1);
digitalWrite(D2,1);
digitalWrite(D3,1);
digitalWrite(D4,1);
  // Start serial
  Serial.begin(115200);
  delay(10);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on ( "/", handleRoot );
  server.on ( "/LED1=ON", ONLED1 );
  server.on ( "/LED1=OFF", OFFLED1 );
  server.on ( "/LED2=ON", ONLED2 );
  server.on ( "/LED2=OFF", OFFLED2 );
  server.on ( "/LED3=ON", ONLED3 );
  server.on ( "/LED3=OFF", OFFLED3 );
  server.on ( "/LED4=ON", ONLED4 );
  server.on ( "/LED3=OFF", OFFLED4 );
  server.on ( "/LED=ON", ONLED );
  server.on ( "/LED=OFF", OFFLED );
  server.on ("/save", handleSave);

  server.begin();
  Serial.println ( "HTTP server started" );

  timeClient.begin();
  Serial.println ( "HTTP timeclient started" );
}

void loop() {
  server.handleClient();
  timeClient.update();
  if(hours+':'+minuts+':'+"00"==timeClient.getFormattedTime()){
    Serial.println("OKOKOKOKOKOKOK");
    digitalWrite(D1,1);
  }
  if(hours2+':'+minuts2+':'+"00"==timeClient.getFormattedTime()){
    Serial.println("OKOKOKOKOKOKOK");
    digitalWrite(D1,0);
  }
  delay(200);
}
