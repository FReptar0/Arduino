#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
int pinLed = 7;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  if (BT.available()) {
    Serial.write(BT.read());
    char data = Serial.read();
    digitalWrite(pinLed, data == 'y' ? HIGH : LOW);
  }
  if (Serial.available() > 0) {
    char data = Serial.read();
    digitalWrite(pinLed, data == 'y' ? HIGH : LOW);
  }
}
