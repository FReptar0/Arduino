#include <Servo.h>

const int fotoResistencia = A0;

Servo servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  int valorFotoResistencia = analogRead(fotoResistencia);
  Serial.print("Luminosidad: ");
  Serial.println(valorFotoResistencia);

  if (valorFotoResistencia >= 400) {
    servo.write(180);
    delay(1000);
  } else if (valorFotoResistencia >= 200) {
    servo.write(90);
    delay(1000);
  } else if (valorFotoResistencia >= 100) {
    servo.write(45);
    delay(1000);
  } else if (valorFotoResistencia < 100) {
    servo.write(0);
    delay(1000);
  }
}
