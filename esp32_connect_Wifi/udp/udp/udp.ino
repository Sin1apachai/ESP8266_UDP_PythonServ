#include "ESP8266WiFi.h"
#include "WiFiUdp.h" 

#define udp_port 40000

WiFiUDP udp;

char ssid[] = "true_home2G_FE8";
char pass[] = "etyt54ha";

void setup()
{

  Serial.begin(9600);
  WiFi.disconnect(true);
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting AccessPoint " + String(ssid));
    delay(2000);
  }

  udp.begin(udp_port);
  Serial.println("---------------------------------------------");
  Serial.println("Connect " + String(ssid) + " !!!!!!");
  Serial.print("IPAddress : ");
  Serial.println(WiFi.localIP());
  Serial.println("Udp Port : " + String(udp_port));
  Serial.println("---------------------------------------------");
  delay(2000);
}

void loop()
{
  int buffer = udp.parsePacket();
  if(buffer>0)
  {
    char text[buffer];
    udp.read(text,buffer);
    Serial.println("------------------------------------------");
    Serial.println("Recive : " + String(text));
    Serial.print("From IPAddress : ");
    Serial.println(udp.remoteIP());
    Serial.println("From Port : " + String(udp.remotePort()));
    Serial.println("------------------------------------------");
      if(udp.beginPacket(udp.remoteIP(),udp.remotePort()))
    {
      udp.write("Echo : ");
      udp.write(text,buffer);
      udp.endPacket();
    }
    udp.flush();
  }
  delay(100);
}
