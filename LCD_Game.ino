#include<LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
byte customChar1[] = {B00101, B11111, B10100, B00100, B01010, B10001, B10001, B00000};
byte customChar2[] = {B00100, B10100, B11111, B00101, B01010, B10001, B10001, B00000};
byte customChar3[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
const byte upKey = 3, dwnKey = 2, rstKey = 4;
void setup() {
  lcd.begin(16, 2);
  // CGRAM
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.createChar(2, customChar3);

  pinMode(upKey, INPUT_PULLUP);
  pinMode(dwnKey, INPUT_PULLUP);
  pinMode(rstKey, INPUT_PULLUP);

}
int pos = -1;
bool hurdles[2][16] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
unsigned long start_time = 0;
void loop() {
  if (!digitalRead(upKey)) {
    pos = 0;
  } else if (!digitalRead(dwnKey)) {
    pos = 1;
  } else if (!digitalRead(rstKey)) {
    pos = -1;
  }
  //man/hero movie
  if (pos == 0) {
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.print(" ");
    //delay(1);
  } else if (pos == 1) {
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.setCursor(0, 0);
    lcd.print(" ");
    //delay(1);
  } else {
    lcd.print("PLAY GAME");
    delay(5);
    lcd.clear();
  }

  if (pos != -1) {
    if (millis() - start_time > 500) {
      start_time = millis();
      // shift hurdles LCD
      for (int i = 0; i <= 14; i++) {
        for (int j = 0; j <= 1 ; j++) {
         hurdles[j][i] = hurdles[j][i+1];
        }
      }
      // new hurdle
      int p = random(2);// 0, 1
      hurdles[p][15] = true;
      hurdles[1 - p][15] = false;
      // show hurdles
      for (int i = 0; i < 16; i++){
        for (int j = 0; j < 2; j++){
          lcd.setCursor(i ,j);
          if (hurdles[j][i]){
            lcd.write(byte(2));
          }else{
            lcd.print(" ");
          }
        }
      }
    }
  }


}
