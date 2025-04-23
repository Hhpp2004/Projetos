#define SensorBoia 12 
#define buser 14
int leiturasensor;

void setup() {
  Serial.begin(9600);
  pinMode(SensorBoia, INPUT); 
  pinMode(buser, OUTPUT);

}

void loop() {
  leiturasensor = digitalRead(SensorBoia); 
  if (leiturasensor == LOW) {
    int time = 400;
    tone(10,440,time);
  }
  delay(300);
}