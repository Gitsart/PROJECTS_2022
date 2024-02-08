#include <Wire.h> //Include Wire library for I2C communication
#include "RTClib.h" //Include RTClib library for DS3231
#include <LiquidCrystal_I2C.h> // include the library code for I2C LCD

LiquidCrystal_I2C lcd(0x3F, 16, 4); 
RTC_DS3231 rtc; //Create an instance of the RTC_DS3231 class

void setup() {
  Serial.begin(9600); //Initialize the serial communication
  Wire.begin(); //Initialize the I2C communication
  rtc.begin(); //Initialize the DS3231
  lcd.init();  // initialize the LCD
  lcd.backlight();
  pinMode(7,OUTPUT);
}

void loop()
{
  DateTime now = rtc.now();

  // Print the time on the LCD module
  lcd.setCursor(0, 0);
  lcd.print("DATE:");
  lcd.print(now.year(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.day(),DEC);
  lcd.setCursor(0, 1);
  lcd.print("TIME:");
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);

  if(now.hour()==22 && now.minute()==50)
  {
    digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  }
}
