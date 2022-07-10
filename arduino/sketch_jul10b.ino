#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED } ; //mac address
IPAddress ip(192, 168, 0, 20) ;
EthernetServer server(80) ;

String HTTP_req;          // stores the HTTP request
boolean LED_status = false;   // state of LED, off by default

void setup()
{
  Ethernet.begin(mac, ip);  // initialize Ethernet device
  server.begin();           // start to listen for clients
  Serial.begin(9600);       // for diagnostics
  pinMode(4, OUTPUT);       // LED on pin 2
}

void loop()
{
  EthernetClient client = server.available();  // try to get client
  if (client) {  // got client?
    //    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {   // client data available to read
        char c = client.read(); // read 1 byte (character) from client
        HTTP_req += c;  // save the HTTP request 1 char at a time
        // last line of client request is blank and ends with \n
        // respond to client only after last line received
        if (c == '\n') {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          // send web page
          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head>");
          client.println("<title>Arduino LED Control</title>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1>LED</h1>");
          client.println("<p>Click to switch LED on and off.</p>");
          client.println("<form method=\"get\">");
          ProcessCheckbox(client);
          client.println("</form>");
          client.println("</body>");
          client.println("</html>");
          Serial.println(HTTP_req) ;
          HTTP_req = "";    // finished with request, empty string
          break;
        }
      } // end if (client.available())
    } // end while (client.connected())
    delay(1);      // give the web browser time to receive the data
    client.stop(); // close the connection
  } // end if (client)
}

// switch LED and send back HTML for LED checkbox
void ProcessCheckbox(EthernetClient cl)
{
  if (HTTP_req.indexOf("LED2=2") != -1) LED_status = true ;
  else if(HTTP_req.indexOf("LED2=1") != -1)LED_status = false ;

  if (LED_status) {    // switch LED on
    digitalWrite(4, HIGH);
    Serial.println("On") ;
    // checkbox is checked
    cl.println("<a href=\"/?LED2=1\">OFF</a>");
  }
  else if(LED_status ==false){              // switch LED off
    digitalWrite(4, LOW);
    Serial.println("Off") ;
    // checkbox is unchecked
    cl.println("<a href=\"/?LED2=2\">ON</a>");
  }
}
