#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  rtc.begin();
}

void loop() {
  DateTime now = rtc.getDateTime();
  String weekDay = rtc.getDOWStr(now.dow);
  Serial.println(weekDay);
  delay(1000);
}
