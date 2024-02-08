#include <Wire.h> //Include Wire library for I2C communication
#include "RTClib.h" //Include RTClib library for DS3231

RTC_DS3231 rtc; //Create an instance of the RTC_DS3231 class

void setup() {
  Serial.begin(9600); //Initialize the serial communication
  Wire.begin(); //Initialize the I2C communication
  rtc.begin(); //Initialize the DS3231

  //Set the date and time on the DS3231 module
  rtc.adjust(DateTime(__DATE__, __TIME__));
}

void loop() {
  DateTime now = rtc.now(); //Get the current date and time from the DS3231

  //Print the date and time in the serial monitor
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000); //Wait for 1 second before printing the next time
}
