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

void handleRoot() {
  char temp[400];
 

  snprintf(temp, 400,
           "<html> <head> <style>body{padding-top: 50px;}.red{background-color: #f44336;}/</style><body><H1>Elmer's Remote Control</h1><form action='.' method='POST'><table><tbody><tr><td></td><tdstyle='text-align:center'><button type='button submit' id='Up'>Up</button> </td><td></td></tr><tr> <tdstyle='text-align:center'> <button type='button submit' id='Left'>Left</button> </td><td> <button type='button submit' class='btn red' id='DISARM'>DISARM</button> </td><td> <button type='button submit' id='Right'>Right</button> </td></tr><tr> <td></td><tdstyle='text-align:center'><button type='button submit' id='Down'>Down</button></td><td></td></tr></tbody></table></form></body></html>");
  server.send(200, "text/html", temp);
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
  server.handleClient();
  dnsServer.processNextRequest();
}
