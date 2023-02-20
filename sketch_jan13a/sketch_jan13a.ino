/* int tempPin = A0;  // Pin del sensor LM35

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(tempPin);
  float voltage = reading * 5.0 / 1024; 
  float temperature = voltage * 100;
  
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");
  
  delay(1000);
}
 */
/* 
#include <DHT.h>

#define DHTPIN 2       // Pin del sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Error al leer del sensor DHT11");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(hum);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("°C");

  delay(2000);
}
 */
#include "DHT.h"        //cargamos la librería DHT
#define DHTPIN 2        //Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11   //Se selecciona el DHT11 (hay //otros DHT)
DHT dht(DHTPIN, DHTTYPE);
   //Se inicia una variable que será usada por Arduino para comunicarse con el sensor
  void
  setup() {
  Serial.begin(9600);  //Se inicia la comunicación serial
  dht.begin();         //Se inicia el sensor
}
void loop() {
  float h = dht.readHumidity();     //Se lee la humedad
  float t = dht.readTemperature();  //Se lee la temperatura
  //Se imprimen las variables
  Serial.println("Humedad: ");
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000);  //Se espera 2 segundos para seguir leyendo //datos
}
