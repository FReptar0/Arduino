// Declare a variable to store the temperature value
int temperature;

void setup() {
  // Set the analog input pin for the thermistor
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the thermistor
  temperature = analogRead(A0);
  // Convert the analog value to temperature using the Steinhart-Hart equation
  temperature = log(10000.0*((1024.0/temperature-1))); 
  temperature = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperature * temperature ))* temperature );
  temperature = temperature - 273.15; 
  // Print the temperature value
  Serial.println(temperature);
  delay(1000);
}
