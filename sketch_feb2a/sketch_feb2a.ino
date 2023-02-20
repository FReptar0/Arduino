#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

double temperatura, humedad, luz;
const int trigPin = 2;
const int echoPin = 3;

//Humedad y fotorresistencia
const int sensorHumedad = A0;
const int fotoResistencia = A1;
long duration;
float distance;

void setup() {
  Serial.begin(9600);
  dht.begin();

  //Sensor de humedad y fotorresistencia
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  leerHumedad();
}

void leerHumedad(){
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  
  Serial.println("Humedad: ");
  Serial.println(humedad);
  Serial.println("Temperatura: ");
  Serial.println(temperatura);
  delay(2000);
}
const int trigPin = 2;
const int echoPin = 3;
const int ledVerde = 6;
const int ledAmarillo = 5;
const int ledRojo = 7;
const int sensorHumedad = A0;
const int fotoResistencia = A1;
long duration;
float distance;

void setup() {


  Serial.begin(9600);
}

void loop() {
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println("cm");

  int sensorValue = analogRead(sensorHumedad);
  Serial.print("Humedad: ");
  int valorHumedad = map(sensorValue, 0, 1023, 100, 0);
  Serial.print(valorHumedad);
  Serial.println("%");

  int valorFotoResistencia = analogRead(A1);
  Serial.print("Luminosidad: ");
  Serial.println(valorFotoResistencia);

  if (distance > 40) {
    Serial.println("Esta en zona verde");
    digitalWrite(ledVerde, HIGH);
    delay(1000);
    digitalWrite(ledVerde, LOW);
  } else if (distance > 20 && distance <= 40) {
    Serial.println("Esta en zona amarilla");
    digitalWrite(ledAmarillo, HIGH);
    delay(1000);
    digitalWrite(ledAmarillo, LOW);
  } else if (distance <= 20) {
    Serial.println("Esta en zona rojo");
    digitalWrite(ledRojo, HIGH);
    delay(1000);
    digitalWrite(ledRojo, LOW);
  }

  if (valorFotoResistencia > 70) {
    if (valorHumedad < 50) {
      Serial.println("Riego necesario, regar en la noche");
    } else if (valorHumedad > 50) {
      Serial.println("Riego adecuado");
    }
  } else if (valorFotoResistencia <= 70) {
    if (valorHumedad < 50) {
      Serial.println("Riego necesario, regar ahora");
    } else if (valorHumedad > 50) {
      Serial.println("Riego adecuado");
    }
  }

  Serial.println();
  delay(1000);
}
