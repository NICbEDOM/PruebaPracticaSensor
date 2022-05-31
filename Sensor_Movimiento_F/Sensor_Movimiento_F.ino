#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pirState=digitalRead(1);
  lcd.setCursor(0,0);
  lcd.print("Analisis");
  if (pirState == LOW){
    lcd.setCursor(0,1);
    lcd.print("sin movimiento");
    delay(500);
    lcd.clear();
  }
  else if (pirState == HIGH){
    lcd.setCursor(0,1);
    lcd.print("ALERTA!!");
    delay(500);
    lcd.clear();
  }
}
//C:\\Users\\ADMINI~1\\AppData\\Local\\Temp\\arduino_build_158424/SensorMovimiento.ino.hex
