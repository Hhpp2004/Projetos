#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <WiFi.h>
#include <WifiClient.h>
#define SensorBoia 12 
#define buser 14
int leiturasensor;

char internet[] = "BugKey";
char senha[] = "Bugkey123";

//IPAddress server_addr(192, 168, 1, 100);
WifiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(SensorBoia, INPUT); 
  pinMode(buser, OUTPUT);
  WiFi.begin(internet, senha);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado.");

  // if (conn.connect(server_addr, 3306, user, password)) {
  //   Serial.println("Conectado ao MySQL!");
  // } else {
  //   Serial.println("Falha na conexão.");
  // }

}

void tom(char pino,int f,int duracao)
{
  float p = 1000.0/f;
  for(int i = 0;i < (duracao/p);i++)
  {
    digitalWrite(pino,HIGH);
    delayMicroseconds(p*500);
    digitalWrite(pino,LOW);
    delayMicroseconds(p*500);
  }
}

void loop() {
  leiturasensor = digitalRead(SensorBoia); 
  if (leiturasensor == LOW) {
    int time = 400;
    tom(buser,440,time);
  }
  delay(300);
}