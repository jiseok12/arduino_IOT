#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// WiFi network
const char* ssid     = "iptime1";
const char* password = "";

ESP8266WebServer server ( 80 );

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600*9, 60000);
String hours="";
String minuts="";

String hours2="";
String minuts2="";

char htmlResponse[9000];
void handleRoot() {
  snprintf ( htmlResponse, 9000,
"<!DOCTYPE html>\
<html lang=\"en\">\
    <meta charset=\"UTF-8\">\
    <link rel=\"stylesheet\" href=\"http://192.168.0.2:5500/arduino.css\">\
    </style>\
</head>\
<body>\
    <span \class=\"title\">콘센트 1</span>\
        <fieldset>\
            <legend \class=\"l1\"><b>시간 설정</b></legend>\
            <label \for=\"odk\">끄는 시간\
                <input id='data_hh'\class=\"ok\" type=\"text\"  name='date_hh'> :\
                <input id='data_mm'\class=\"ok\" type=\"text\"  name='date_mm'>\
            </label>\
            <br>\
            <label \for=\"odk\">키는 시간\
                <input id='data_hh2' \class=\"ok\" type=\"text\"name='date_hh2'> :\
                <input id='data_mm2' \class=\"ok\" type=\"text\" name='date_mm2'>\
            </label>\
        </fieldset>\
        <fieldset>\
            <legend \class=\"l2\"><b>자동차단 전력량 설정 on/off</b></legend>\
            <label \for=\"odk\">차단할 전력량<input type=\"text\"> W</label>\
        </fieldset>\
        <fieldset>\
            <legend \class=\"l3\"><b>AI 자동모드</b></legend>\
            <p>NWP 앱이 추천하는 전력량을 기준으로 전력이 자동으로 차단됩니다.</p>\
            <a href=\"\"><button class=\"ON\">ON</button></a>\
            <a href=\"\"><button class=\"ON\">OFF</button></a>\
        </fieldset>\
    <button \class=\"bu\" onclick='timego()'>완료</button>\
    <script>\
      function timego(){\
        let hh=document.getElementById('data_hh');\
        let mm=document.getElementById('data_mm');\
        let hh2=document.getElementById('data_hh2');\
        let mm2=document.getElementById('data_mm2');\
        location.href='/save?hh='+hh.value+'&mm='+mm.value+'&hh2='+hh2.value+'&mm2='+mm2.value;\
      }\
    </script>\
    <\div \class=\"bottom_menu\">\
        <\div>\
            <span \class=\"material-symbols-outlined a\">home</span>\
        </\div>\
        <\div>\
            <span \class=\"material-symbols-outlined a\">add</span>\
        </\div>\
        <\div>\
            <span \class=\"material-symbols-outlined a\">compost</span>\
        </\div>\
        <\div>\
            <span \class=\"material-symbols-outlined a\">settings</span>\
        </\div>\
    </\div>\
</body>\
</html>"); 
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
  
  server.send ( 200, "text/html", "<script>location.href='/';</script>");  
}
void setup() {
pinMode(D1,OUTPUT);
digitalWrite(D1,1);
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
