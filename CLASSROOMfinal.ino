#include<DHT.h>

#define fanpina 13
#define fanpinb 12
#define AC 1
#define lighta 11
#define lightb 10
#define lightc 9
#define lightd 8
#define lighte 7
#define lightf 6
#define pira 2
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

   void setup()
   {
    pinMode(pira,INPUT);
   
digitalWrite(pira,LOW);

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

   void loop()
   {
    float humidity = dht.readHumidity();        // reading and storing humidity value to a variable named humidity
  float temperature = dht.readTemperature();  // reading and storing temperature value to a variable named temperature
  Serial.print("Humidity= ");
  Serial.print(humidity);                     // Printing the humidity
  Serial.print("%  Temperature=  ");
  Serial.print(temperature);                  // Printing the temperature
  Serial.println("°C");


  digitalWrite(pira,LOW);

  if( digitalRead(pira)== HIGH)
  {
    
    digitalWrite(fanpina,LOW);
    digitalWrite(lighta,HIGH);
    digitalWrite(lightb,HIGH);
    digitalWrite(lightc,HIGH);
    digitalWrite(fanpinb,LOW);
    digitalWrite(lightd,HIGH);
    digitalWrite(lighte,HIGH);
    digitalWrite(lightf,HIGH);
    Serial.print("motion1");
    delay(1000);

     if(temperature>=32.00)
    {
      digitalWrite(5,HIGH);
    }

    else
    {
      digitalWrite(5,LOW);
      
    }
    
  }

  else
  { digitalWrite(fanpina,HIGH);
    digitalWrite(lighta,LOW);
    digitalWrite(lightb,LOW);
    digitalWrite(lightc,LOW);
    digitalWrite(fanpinb,HIGH);
    digitalWrite(lightd,LOW);
    digitalWrite(lighte,LOW);
    digitalWrite(lightf,LOW);
    delay(1000);
    
  }
   }
