#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x3F,16,4);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  DateTime now = rtc.now();

  // Display the date and time on the LCD
  lcd.setCursor(0,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(0,1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  if(now.minute() < 10) {
    lcd.print('0'); // add a leading zero if minute is less than 10
  }
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  if(now.second() < 10) {
    lcd.print('0'); // add a leading zero if second is less than 10
  }
  lcd.print(now.second(), DEC);

  delay(1000);
}
