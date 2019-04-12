#include"SoftwareSerial.h"
SoftwareSerial myserial(0,1);
 
char data=4;                      //define variable to store data from bluetooth

int motorpin1 = 8;                  //define digital output pin no.

int motorpin2 = 9;                        //define digital output pin no.

void setup () {
  Serial.begin(9600);                     //defining baud rate
  myserial.begin(9600);
  pinMode(motorpin1,OUTPUT);              //set pin 3 as output
  pinMode(motorpin2,OUTPUT);              // set pin 4 as output
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop () 
{
  if(Serial.available() > 0)              // Send data only when you receive data:
    {
    data = Serial.read();                //Read the incoming data and store it into variable data
    Serial.println(data);                  //Print Value inside data in Serial monitor 
      if(data == '1')
      {                  //Checks whether value of data is equal to 1 means locking of door
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,HIGH);
      digitalWrite(LED_BUILTIN,HIGH);
     
      }
      else if(data=='0')                //Checks whether value of data is equal to 0 means unlocking of door
        { digitalWrite(motorpin1,HIGH); //moves in reverse direction
          digitalWrite(motorpin2,LOW);
        }
     
     } 

}

