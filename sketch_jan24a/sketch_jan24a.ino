int buttonState = 0;

// Definir la cantidad de pulsadores

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  buttonState = digitalRead(2);
  //Agregar validacion para determinar que boton fue el que se encendio
  if (buttonState == HIGH) {
    Serial.println("El boton 1 esta encendido");
    // Indicar que boton se prendio
    delay(500);
  }
}
