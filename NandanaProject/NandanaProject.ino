#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
 

}

void loop() {
  int LDR = analogRead(A0);
  Serial.println(LDR);
  lcd.setCursor(0,0);
  lcd.print("LIGHT BRIGHTNESS");

  if(LDR>360) {
    lcd.setCursor(3,1);
    lcd.print(" DIM");
  } else {
    lcd.setCursor(3,1);
    lcd.print("HIGH");
  }
 

}
