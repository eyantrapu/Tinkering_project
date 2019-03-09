/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESP8266WebServer.h>
#include<ESP8266mDNS.h>

MDNSResponder mdns;
/* Set these to your desired credentials. */
const char* ssid = "home";
const char* password = "12345";
ESP8266WebServer server(80);
int light1 =D2;
int light2 =D3;
int light3 =D4;
int light4 =D5;
char webpage[] PROGMEM = R"====(
<html>
<head>
</head>
<body>

<button>
<a href=\l1>Light 1
</a>
</button>
<button>
<a href=\l2>Light 2
</a>
</button>
<button>
<a href=\l3>light 3
</a>
</button>
<button>
<a href=\l4>light 4
</a>
</button>

</body>
</html>
)====";

  void light_1()
{
  digitalWrite(light1,!digitalRead(light1));
  server.send_P(200,"text/html",webpage);
  
  }
  void light_2()
{
  digitalWrite(light2,!digitalRead(light2));
  server.send_P(200,"text/html",webpage);
  
  }
  void light_3()
{
  digitalWrite(light3,!digitalRead(light3));
  server.send_P(200,"text/html",webpage);
  
  }
  void light_4()
{
  digitalWrite(light4,!digitalRead(light4));
  server.send_P(200,"text/html",webpage);
  
  }
/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */


void setup() {
   
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(light3,OUTPUT);
  pinMode(light4,OUTPUT);

	delay(1000);
	Serial.begin(115200);
	Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
	Serial.print("Configuring access point...");
    if(mdns.begin("home",WiFi.localIP()))
  {
    Serial.println("MDNS Responder Started");
  }  
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);
  }
      Serial.println("Connecting Wifi...");
   
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
//  while(!MDNS.begin("home",WiFi.localIP())) {
//    Serial.println("Error setting up MDNS responder!");
//    while(1) { 
//      delay(1000);
//    }
//  }
//  Serial.println("mDNS responder started");
  server.on("/",[](){server.send_P(200,"text/html",webpage);});
  server.on("/l1",light_1);
  server.on("/l2",light_2);
  server.on("/l3",light_3);
  server.on("/l4",light_4);
  server.begin();
 MDNS.addService("http","tcp",80);
}
void loop() {
	server.handleClient();
}

