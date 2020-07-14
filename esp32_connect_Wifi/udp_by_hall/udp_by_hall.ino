#include "ESP8266WiFi.h"
#include "WiFiUdp.h" 

#define udp_port 4000

WiFiUDP udp;

char ssid[] = "true_home2G_FE8";
char pass[] = "etyt54ha";

char udp_address[] = "192.168.1.33";

void setup() {
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

void loop() {
  uint8_t buffer[50] = "hello world";

  udp.beginPacket(udp_address, udp_port);
  udp.write(buffer, 11);
  udp.endPacket();

  memset(buffer, 0, 50);
  udp.parsePacket();

  if(udp.read(buffer, 50) > 0){
    Serial.println("Read its");
    Serial.print("Server to client: ");
    Serial.println((char *)buffer);
  }
  delay(500);
}
