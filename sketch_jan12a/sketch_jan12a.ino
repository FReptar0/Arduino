//Paso 1
const int sensorPin = A0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}
 
void loop()
{
  //Paso 2
  float valueAdc = analogRead(sensorPin);

  //Paso 3
  float volts = (valueAdc / 1023.0) * 5;

  //Paso 4
  float celsius = volts * 100.00; 
  //Paso 5
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);

  if (celsius >= 20 ){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, HIGH);
  }
}