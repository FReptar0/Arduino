void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.print("Valor del sensor: ");
  Serial.print(map(sensorValue, 0, 1023, 100, 0));
  Serial.print("%\n");
  delay(1000);
}
