#include <Ultrasonic.h>

#include<Servo.h>
Servo myservo;

#define LA 2
#define LB 3
#define RA 4
#define RB 5


Ultrasonic ultrasonic(A2 ,A1);

int pos=70;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
 

 
  myservo.attach(9);
  myservo.write(pos);
}
  


void loop() {
  myservo.write(pos);
  // put your main code here, to run repeatedly:
  distance = ultrasonic.Ranging(CM);
  
  

  if (distance > 10)
  {
    forward();
    
  } 
  else if (distance <=10)
  {
     Stop();
     angle_90();
     delay(20);
     distance = ultrasonic.Ranging(CM);
     delay(20);
     angledec_0();
     if (distance > 10)
     {
     leftward();
     }
     else if (distance <= 10)
     {
     angle_180();
     distance = ultrasonic.Ranging(CM);
     delay(20);
     angleinc_0();
     if (distance > 10)
     {
     rightward();
     }
     else if (distance <= 10)
     {
     Stop();
     }
     }
  }
}
     
     
     
  
void forward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void backward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void leftward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);

  delay(1000);
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
  
}
void rightward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);

  delay(1000);
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
  
  
  
}
void Stop() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, LOW);
}
void angle_90()
{
 delay(200);
  for (pos = 70; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
  void angledec_0()
  {
  for (pos = 180; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  
}
void angle_180()
 {
  for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 }
 void angleinc_0(){
 for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 }
 
  
 


