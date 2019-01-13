#include <DNSServer.h>

#include <WiFiServerSecure.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266WiFiType.h>
#include <ESP8266WiFiAP.h>
#include <WiFiServer.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "Elmer"
#define APPSK  "ElmerWasHere!"
#endif

const char *ssid = APSSID;
const char *password = APPSK;

const byte        DNS_PORT = 53;          // Capture DNS requests on port 53
DNSServer         dnsServer;              // Create the DNS object

ESP8266WebServer server(80);
bool Armed = true;
String OutputBuffer = "";

const char HTMLARMED[] = 
"<html>"
""
"<head>"
"    <style>"
"        body {"
"            padding-top: 50px;"
"        }"
"        "
"        .red {"
"            background-color: #f44336;"
"            width: 100%;"
"            height: 140px;"
"        }"
"        "
"        button {"
"            width: 75%;"
"            height: 100px;"
"        }"
"    </style>"
"</head>"
"    <body width=100%>"
"        <div width='100%'>"
"            <div align=center>"
"                <h3>Elmer's Remote Control</h3></div>"
"            <form action='/' method='POST'>"
"<input type='hidden' name='shim' value='' />"
"                <table width='100%'>"
"                    <tbody>"
"                        <tr>"
"                            <td></td>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Up'>Up</button>"
"                            </td>"
"                            <td></td>"
"                        </tr>"
"                        <tr>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Left'>Left</button>"
"                            </td>"
"                            <td>"
"                                <button type='submit' class='btn red' name='action' value='DISARM' style='RED'>ARM</button>"
"                            </td>"
"                            <td>"
"                                <button type='submit'  name='action' value='Right'>Right</button>"
"                            </td>"
"                        </tr>"
"                        <tr>"
"                            <td></td>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Down'>Down</button>"
"                            </td>"
"                            <td></td>"
"                        </tr>"
"                    </tbody>"
"                </table>"
"            </form>"
"        </div>"
"    </body>"
""
"</html>";

const char HTMLDISARMED[] = 
"<html>"
""
"<head>"
"    <style>"
"        body {"
"            padding-top: 50px;"
"        }"
"        "
"        .red {"
"            background-color: #008000;"
"            width: 100%;"
"            height: 140px;"
"        }"
"        "
"        button {"
"            width: 75%;"
"            height: 100px;"
"        }"
"    </style>"
"</head>"
"    <body width=100%>"
"        <div width='100%'>"
"            <div align=center>"
"                <h3>Elmer's Remote Control</h3></div>"
"            <form action='/' method='POST'>"
"<input type='hidden' name='shim' value='' />"
"                <table width='100%'>"
"                    <tbody>"
"                        <tr>"
"                            <td></td>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Up'>Up</button>"
"                            </td>"
"                            <td></td>"
"                        </tr>"
"                        <tr>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Left'>Left</button>"
"                            </td>"
"                            <td>"
"                                <button type='submit' class='btn red' name='action' value='DISARM' style='RED'>DISARM</button>"
"                            </td>"
"                            <td>"
"                                <button type='submit' name='action' value='Right'>Right</button>"
"                            </td>"
"                        </tr>"
"                        <tr>"
"                            <td></td>"
"                            <td style='text-align:center'>"
"                                <button type='submit' name='action' value='Down'>Down</button>"
"                            </td>"
"                            <td></td>"
"                        </tr>"
"                    </tbody>"
"                </table>"
"            </form>"
"        </div>"
"    </body>"
""
"</html>";

void handleRoot() {

 String message = "Request received:\n";
// for (int i = 0; i < server.args(); i++) {
//
//message += "Arg nº" + (String)i + " –> ";
//message += server.argName(i) + ": ";
//message += server.arg(i) + "\n";
//
//} 
// for (int i = 0; i < server.headers(); i++) {
//
//message += "Header nº" + (String)i + " –> ";
//message += server.headerName(i) + ": ";
//message += server.header(i) + "\n";
//
//} 
//message += server.arg("plain");
//message += "\n";
//  Serial.println(message);

  if (server.hasArg("action"))
  {
    String a = server.arg("action");

    if (a.equals( "DISARM"))
    { 
        Serial.println(Armed);
        Armed = !Armed;
        if (Armed)
          OutputBuffer +="A";
        else
          OutputBuffer +="!";
          
        
    }

    // only look at other commands if the system is armed!
    if (Armed)
    {
      if (a.equals( "Left"))
          OutputBuffer +="L";
      if (a.equals( "Right"))
          OutputBuffer +="R";
      if (a.equals( "Up"))
          OutputBuffer +="U";
      if (a.equals( "Down"))
          OutputBuffer +="D";
    }
  }

  if (Armed==true)
    server.send(200, "text/html", HTMLARMED);
  
  else
    server.send(200, "text/html", HTMLDISARMED);
  
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  Serial.print("Configuring access point... SSID:");
  Serial.print(ssid);
  Serial.print(" PWD:");
  Serial.print(password);

  Serial1.begin(115200); //setting up the Tx for arduino to watch. TX pin on ESP is D8
   /* You can remove the password parameter if you want the AP to be open. */
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);  Serial.println("");

 

  dnsServer.start(DNS_PORT, "*", myIP);
 

  server.on("/", handleRoot);
  /*server.on("/test.svg", drawGraph);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });*/
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  int count = WiFi.softAPgetStationNum();
  if (count==0 and Armed == true)
  {
    // nobody watching... disarm!
    Armed = false;
    OutputBuffer +="!";
    Serial.println("No wifi clients... disarming");
  }

  if (OutputBuffer.length()>0)
  {
    Serial1.print(OutputBuffer);
    OutputBuffer = "";
  }
  server.handleClient();
  dnsServer.processNextRequest();
}
