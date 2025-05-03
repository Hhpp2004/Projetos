#include <WiFi.h>
#include <WiFiMulti.h>
#include <Ultrasonic.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

#define echo 18
#define trig 19
#define SensorBoia 12
#define buser 14

WiFiMulti wifiMulti;
unsigned long duration;
long distancia;
int leiturasensor;
const char* ssid = "Henrique";
const char* password = "34055785";

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  pinMode(SensorBoia, INPUT);
  pinMode(buser, OUTPUT);
  wifiMulti.addAP(ssid, password);
 Serial.println("Conectando ao Wi-Fi...");
  
  // Espera até se conectar a uma rede
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Conectado ao Wi-Fi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  configTime(-3 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Configurando horário via NTP...");
  while (time(nullptr) < 100000) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nHorário configurado com sucesso.");
}

String getCurrentTime() {
  time_t now = time(nullptr);
  struct tm* localTime = localtime(&now);

  char buffer[20];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

  return String(buffer);  // Classe String do Arduino
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
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distancia = duration * 0.034 / 2;
  float nivel = 9 - distancia;
  Serial.println("Nivel de agua: ");
  Serial.println(nivel);

  leiturasensor = digitalRead(SensorBoia);
  if (leiturasensor == LOW) {
    int time = 400;
    String currentTime = getCurrentTime();
    Serial.println("Horário do evento: " + currentTime);
    tom(buser, 440, time);
  }
  delay(000);
}