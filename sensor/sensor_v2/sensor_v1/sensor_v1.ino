#include <WiFi.h>
#include <Ultrasonic.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#define SensorBoia 12
#define buser 14

unsigned long duration;
long distancia;
int leiturasensor;
// Ultrasonic ultrassom(18, 19);
const char* ssid = "Henrique";
const char* password = "34055785";

void setup() {
  pinMode(19,OUTPUT);
  pinMode(18,INPUT);
  Serial.begin(9600);
  pinMode(SensorBoia, INPUT);
  pinMode(buser, OUTPUT);
  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.println("Conectando no Wifi");
  // }
  // Serial.println("Conectado na internet WiFi");
}

void tom(int pino, int f, int duracao) { 
  float p = 1000.0 / f;
  for (int i = 0; i < (duracao / p); i++) {
    digitalWrite(pino, HIGH);
    delayMicroseconds(p * 500);
    digitalWrite(pino, LOW);
    delayMicroseconds(p * 500);
  }
}

void loop() {
  digitalWrite(19, LOW);
  delayMicroseconds(2);
  digitalWrite(19, HIGH);
  delayMicroseconds(10);
  digitalWrite(19, LOW);

  duration = pulseIn(18, HIGH);
  distancia = duration * 0.034 / 2;
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  leiturasensor = digitalRead(SensorBoia);
  if (leiturasensor == LOW) {
    int time = 400;
    tom(buser, 440, time);
  }
  delay(300);
}
