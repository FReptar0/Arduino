void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() == '1') {
    digitalWrite(13, HIGH);
  }
  if (Serial.read() == '0') {
    digitalWrite(13, LOW);
  }
  if(Serial.read().)
}
