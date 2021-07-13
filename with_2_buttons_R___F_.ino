const byte ledPin = 13;
const byte button1 = 2;
const byte button2 = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

}
bool state = false;
void loop() {
  if (digitalRead(button1) == 0){
    while(digitalRead(button1) == 0);
    digitalWrite(ledPin, !state);
  }
  if (digitalRead(button2) == 0){
    digitalWrite(ledPin, state);
    while(digitalRead(button2) == 0);
  }

}
