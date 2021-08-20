#include<SoftwareSerial.h>
SoftwareSerial ser(A0, A1);
void setup() {
  pinMode(A5, INPUT_PULLUP);
  Serial.begin(9600);
  ser.begin(9600);
}
char button = '0';

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    ser.write(ch);
  }
  if (!digitalRead(A5)) {
    while (!digitalRead(A5));
    if (button == '0') {
      button = '1';
    } else {
      button = '0';
    }
    Serial.write(button);
  }
}
