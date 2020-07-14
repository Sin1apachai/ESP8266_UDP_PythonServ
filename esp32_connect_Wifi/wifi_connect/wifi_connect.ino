#include <ESP8266WiFi.h>

const char* ssid     = "true_home2G_FE8";
const char* password = "etyt54ha";

void setup() 
{
   Serial.begin(115200);
   Serial.println("Starting...");

   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) 
   {
      delay(250);
      Serial.print(".");
   }

   Serial.println("WiFi connected");  
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
}

void loop() 
{
}
