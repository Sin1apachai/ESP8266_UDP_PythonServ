#include <WiFi.h>
#include <WiFiUdp.h>

char ssid[] = "true_home2G_FE8";
const char * pwd = "etyt54ha";

const char * udpAddress = "192.168.1.100";
const int udpPort = 44444;

WiFiUDP udp;

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, pwd);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  udp.begin(udpPort);
}

void loop(){
  
  uint8_t buffer[50] = "hello world";
  
  udp.beginPacket(udpAddress, udpPort);
  udp.write(buffer, 11);
  udp.endPacket();
  memset(buffer, 0, 50);
  udp.parsePacket();
  
  if(udp.read(buffer, 50) > 0){
    Serial.print("Server to client: ");
    Serial.println((char *)buffer);
  }
  delay(500);
}
