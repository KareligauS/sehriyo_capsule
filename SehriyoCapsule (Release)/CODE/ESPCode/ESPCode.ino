
#include"definitions.h"
#include <ESP8266WiFi.h>

int SERVER = 301;

const char *ssid = "CapsuleSehriyo";
const char *password = "Sehriyo12345678";

WiFiServer server(SERVER); //just pick any port number you like
WiFiClient client;

char buff[100];

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Соединяемся с ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi подключен");

  // Start the server
  server.begin();
  Serial.println("Сервер готов к работе ");

  // Print the IP address
  Serial.print(WiFi.localIP());
  Serial.print(':');
  Serial.println(SERVER);
  
}

void loop() {
  waitClientConnect(client);
  if(Serial.available()>-1){
    String req = client.readStringUntil('\r');
//    delay(10);
//    Serial.println(req);
    int key = req[6];
    int key_number = req[6] - '0';
     
    Serial.println(req);
}
  outWebPage(client);
}
void Error(){
  Serial.println("ERROR");
}
void waitClientConnect(WiFiClient&client){
  client = server.available();
  if (!client) {
    return;
  }
  while (!client.available()) {
    delay(1);
  }
}

void outWebPage(WiFiClient&client){
  String p = static_cast<String>(HTML) + static_cast<String>(CSS) + static_cast<String>(BODY) + static_cast<String>(JS) + static_cast<String>("</html>");
  client.print(p);
  client.flush();
  delay(1);
}
