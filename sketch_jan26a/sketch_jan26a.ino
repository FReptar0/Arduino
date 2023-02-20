#include <Servo.h>
Servo servoMotor;

const int fotoResistencia = A0;
const int sensorHumedad = A1;
const int lm35 = A2;

const int relayBombaPin = 2;
const int pinServo = 7;
const int trigPin = 8;
const int echoPin = 9;

float distance;
long duration;

int aux = 15;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayBombaPin, OUTPUT);

  servoMotor.attach(pinServo);

  servoMotor.write(0);
  digitalWrite(relayBombaPin, LOW);
}

void loop() {

  int valorFotoResistencia = analogRead(fotoResistencia);
  Serial.print("Luminosidad: ");
  Serial.print(valorFotoResistencia);
  Serial.println("%");
  delay(100);


  int sensorValue = analogRead(sensorHumedad);
  Serial.print("Humedad: ");
  int valorHumedad = map(sensorValue, 0, 1023, 100, 0);
  Serial.print(valorHumedad);
  Serial.println("%");
  delay(100);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);


  float temperatura = analogRead(lm35);
  temperatura = (5.0 * temperatura * 100.0) / 1024.0;
  Serial.print(temperatura);
  Serial.println("°C");
  delay(1000);
  Serial.println();

  /* Apagar bomba cuando supere 70% de humedad */
  if (valorHumedad > 60) {
    digitalWrite(relayBombaPin, HIGH);
  } else if (valorHumedad < 60) {
    digitalWrite(relayBombaPin, LOW);
  }

  if (distance < 30) {
    servoMotor.write(aux);
    aux = aux + 15;
  }
}
