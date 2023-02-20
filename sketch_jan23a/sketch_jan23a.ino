int boton1 = 4;
int boton2 = 6;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly
  int estado = digitalRead(boton1);
  int estado2 = digitalRead(boton2);
  int cont = 1;

  if (digitalRead(boton1) != estado) {
    digitalWrite(led, HIGH);
    delay(200);
  }

  if (digitalRead(boton2) != estado2) {
    Serial.println(digitalRead(boton2));
    digitalWrite(led, LOW);
    delay(200);
  }
  
}
