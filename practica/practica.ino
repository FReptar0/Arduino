const int btn1 = 5;
const int btn2 = 4;
const int btn3 = 3;
const int btn4 = 2;
const int btn5 = 7;

String numBin;

const int pinLed = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
}

void loop() {
  int btn1S = digitalRead(btn1);
  int btn2S = digitalRead(btn2);
  int btn3S = digitalRead(btn3);
  int btn4S = digitalRead(btn4);

  numBin = String(btn1S) + String(btn2S) + String(btn3S) + String(btn4S);

  if (digitalRead(btn5) == HIGH) {
    Serial.println(numBin);
    int numD = Serial.parseInt();
    delay(500);
    for (int i = 0; i < numD; i++) {
      digitalWrite(pinLed, HIGH);
      delay(500);
      digitalWrite(pinLed, LOW);
      delay(500);
    }
  }

/*   if (Serial.available() > 0) {
  String numB = String(btn1S) + String(btn2S) + String(btn3S) + String(btn4S);
  Serial.println(numB);
  } */
}


//Código para python
/* import serial

ser = serial.Serial('COM3', 9600)

while True:
    numBinario = ser.readLine().decode().strip()
    numDecimal = int(binary, 2)
    ser.write(str(numDecimal).encode())
    println(numDecimal)
 */