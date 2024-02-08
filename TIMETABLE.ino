#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include<SoftwareSerial.h>

SoftwareSerial BTserial(0,1);
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x3F,16,4);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  lcd.init();
  lcd.backlight();
  pinMode(7,OUTPUT);
  BTserial.begin(9600);
}

void loop() {

if(BTserial.available()) {
  String text = BTserial.readStringUntil('/n');
  lcd.clear();
  lcd.setCursor(3,3);
  lcd.print(text);
}

  
  DateTime now = rtc.now();



  if(now.hour()==9 && now.minute()>= 15 || now.hour()==11 && now.minute()==14)
  {
     // Display the date and time on the LCD
  lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  

  lcd.setCursor(2,2);
  lcd.print("NOW: HDL");
  lcd.setCursor(2,3);
  lcd.print("NEXT:AMP");
  }
  
  else if(now.hour()==11 && now.minute()>=15 || now.hour()==12 && now.minute()==10)
  {
      // Display the date and time on the LCD
  lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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
  lcd.setCursor(2,2);
  lcd.print("NOW:AMP");
  lcd.setCursor(2,3);
  lcd.print("NEXT:Break");
  
  }

  else if(now.hour()==12 && now.minute()>=11 || now.hour()==13 && now.minute()<=30)
  {
      lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  lcd.setCursor(2,2);
  lcd.print("NOW:Break");
  lcd.setCursor(2,3);
  lcd.print("NEXT:CS");
  
    
  }

  else if(now.hour()==13 && now.minute()>=31 || now.hour()==14 && now.minute()<=15)
  {
      lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  lcd.setCursor(2,2);
  lcd.print("NOW:CS");
  lcd.setCursor(2,3);
  lcd.print("NEXT:Break");
  
  }

  else if(now.hour()==14 && now.minute()>=16 || now.hour()==14 && now.minute()<=25)
  {
      lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  lcd.setCursor(2,2);
  lcd.print("NOW:Break");
  lcd.setCursor(2,3);
  lcd.print("NEXT:PNS");
  
  }
  else if(now.hour()==14 && now.minute()>=26 || now.hour()==15 && now.minute()<=59)
  {
     
      lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  lcd.setCursor(2,2);
  lcd.print("NOW:PNS");
  }
 
 if(now.hour()>=16 && now.minute()>=01 || now.hour()<=9 && now.minute()<=14)
  {
      lcd.setCursor(3,0);
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);

  lcd.setCursor(3,1);
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

  lcd.setCursor(2,2);
  lcd.print("Class Over");
  }

  if(now.hour()==9 && now.minute()==15||now.hour()==11 && now.minute()==00||now.hour()==12 && now.minute()==10||now.hour()==13 && now.minute()==30||now.hour()==14 && now.minute()==15||now.hour()==14 && now.minute()==25||now.hour()==16 && now.minute()==00)
  {
    digitalWrite(7,HIGH);
    delay(5000);
    digitalWrite(7,LOW);
  }
  
}
