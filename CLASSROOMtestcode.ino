#include <DHT.h>             //includes the DHT library 

#define fanpina 13
#define fanpinb 12
#define AC 1
#define lighta 11
#define lightb 10
#define lightc 9
#define lightd 8
#define lighte 7
#define lightf 6
#define ACpin 5
#define pira 2
#define pirb 3
#define DHTPIN 4          // the pin that the DHT11 is connected to
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);  //object created for reading data from the dht sensor with pin and sensor type as arguments


void setup() {
pinMode(pira,INPUT);
pinMode(pirb,INPUT);
digitalWrite(pira,LOW);
digitalWrite(pirb,LOW);

pinMode(fanpina,OUTPUT);
pinMode(fanpinb,OUTPUT);
pinMode(lighta,OUTPUT);
pinMode(lightb,OUTPUT);
pinMode(lightc,OUTPUT);
pinMode(lightd,OUTPUT);
pinMode(lighte,OUTPUT);
pinMode(lightf,OUTPUT);

Serial.begin(9600);
dht.begin();

}

void loop() {

  float humidity = dht.readHumidity();        // reading and storing humidity value to a variable named humidity
  float temperature = dht.readTemperature();  // reading and storing temperature value to a variable named temperature
  Serial.print("Humidity= ");
  Serial.print(humidity);                     // Printing the humidity
  Serial.print("%  Temperature=  ");
  Serial.print(temperature);                  // Printing the temperature
  Serial.println("°C");


  

  if( digitalRead(pira)== HIGH)
  {
    
    digitalWrite(fanpina,HIGH);
    digitalWrite(lighta,HIGH);
    digitalWrite(lightb,HIGH);
    digitalWrite(lightc,HIGH);
    Serial.print("motion1");
    delay(1000);

     if(temperature>=32.00)
    {
      digitalWrite(ACpin,HIGH);
    }

    else
    {
      digitalWrite(ACpin,LOW);
      
    }
    
  }

  else
  { digitalWrite(fanpina,LOW);
    digitalWrite(lighta,LOW);
    digitalWrite(lightb,LOW);
    digitalWrite(lightc,LOW);
    delay(1000);
    
  }

 if(digitalRead(pirb)==HIGH)
 {

  
    digitalWrite(fanpinb,HIGH);
    digitalWrite(lightd,HIGH);
    digitalWrite(lighte,HIGH);
    digitalWrite(lightf,HIGH);
    delay(1000);

        if(temperature>=32.00)
    {
      digitalWrite(ACpin,HIGH);
    }

    else
    {
      digitalWrite(ACpin,LOW);
      
    }
 }
 else
 {
    digitalWrite(fanpinb,LOW);
    digitalWrite(lightd,LOW);
    digitalWrite(lighte,LOW);
    digitalWrite(lightf,LOW);
    delay(1000);
  
 }

  
}
