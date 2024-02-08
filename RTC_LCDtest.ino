#include <Wire.h> //Include Wire library for I2C communication
#include "RTClib.h" //Include RTClib library for DS3231 
#include <LiquidCrystal_I2C.h> // include the library code for I2C LCD

LiquidCrystal_I2C lcd(0x27, 16, 4); 
RTC_DS3231 rtc; //Create an instance of the RTC_DS3231 class

void setup() {
  Serial.begin(9600); //Initialize the serial communication
  Wire.begin(); //Initialize the I2C communication
  rtc.begin(); //Initialize the DS3231
  lcd.init();  // initialize the LCD
  lcd.backlight();
}

void loop() {
  DateTime now = rtc.now(); //Get the current date and time from the DS3231
  lcd.setCursor(0,0); // set the cursor to the top left corner
  lcd.print(now.year(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.day(),DEC);

}
