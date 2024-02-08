char t;

#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3);
const int Pin=2; 
void setup() {
pinMode(Pin, INPUT);  
 
pinMode(13,OUTPUT);   
pinMode(12,OUTPUT);   
pinMode(11,OUTPUT);   
pinMode(10,OUTPUT);   
pinMode(9,OUTPUT);   
Serial.begin(9600);
MyBlue.begin(9600); 
}
 
void loop()
{
  
if(MyBlue.available()){
  t = MyBlue.read();
  Serial.println(t);
}
 
if(t == 'F'){           
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'R'){      
  digitalWrite(11,HIGH);
  digitalWrite(13,LOW);
}
 
else if(t == 'L')
{      
  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
}


 
else if(t == 'S'){      
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
delay(100);

}
