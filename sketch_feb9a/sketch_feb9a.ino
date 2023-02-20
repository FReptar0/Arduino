int btn8, btn4, btn2, btn1;
char numB[4];
int valorB = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  int valorD = 0;
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn8, INPUT);
}

void loop() {
  b1 = digitalRead(btn1);
  b2 = digitalRead(btn2);
  b4 = digitalRead(btn4);
  b8 = digitalRead(btn8);
  if (b1 == HIGH){
    numB[0] = '1';
  }
  if (b2 == HIGH){
    numB[1] = '1';
  }
  if (b4 == HIGH){
    numB[2] = '1';
  }
  if (b8 == HIGH){
    numB[3] = '1';
  }
  Serial.write(numB);
  delay(1000);
}
