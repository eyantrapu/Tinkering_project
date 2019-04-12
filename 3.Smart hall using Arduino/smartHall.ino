#include <NewPing.h>
 
#define TRIGGER_PIN1 3
#define TRIGGER_PIN2 5 

#define ECHO_PIN1 2
#define ECHO_PIN2 4

#define MAX_DISTANCE 20000
#define led1 9
#define led2 10
#define motor1 11
// NewPing setup of pins and maximum distance
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 
 
void setup() {
   Serial.begin(9600);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(motor1,OUTPUT);
}

void loop() {
   unsigned int distance1 = sonar1.ping_cm();
   unsigned int distance2 = sonar2.ping_cm();
   Serial.print(distance1);
   Serial.println("cm");
   Serial.print(distance2);
   Serial.println("cm");
   if(distance1<15){
    digitalWrite(led1, HIGH);
    analogWrite(motor1,255);
   }else{
    digitalWrite(led1, LOW);
    analogWrite(motor1,0);
   }
   if(distance2<15){
    digitalWrite(led2, HIGH);
   }else{
    digitalWrite(led2, LOW);
   }
   delay(500);
}
