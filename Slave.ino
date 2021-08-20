void setup() {
  Serial.begin(9600);
  pinMode(A5, OUTPUT);

}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == '1') {
      digitalWrite(A5, 1);
      Serial.println("LED is ON");
    } else if (ch == '0') {
      digitalWrite(A5, 0);
      Serial.println("LED is OFF");
    }
  }
}
