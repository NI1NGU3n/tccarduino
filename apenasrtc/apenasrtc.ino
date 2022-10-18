#include <LiquidCrystal.h>
//código 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Vitor rodrigues izidoro");
}

void loop(){
  int segundos;
  lcd.setCursor(0, 1);
  segundos = millis() / 1000;
  lcd.print("2infoB");
}