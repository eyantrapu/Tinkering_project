
/*------ Arduino Fire Fighting Robot Code----- */

#include <Servo.h>
Servo myservo;

int pos = 0;
boolean fire = false;

/*-------defining Inputs------*/
#define Left_S 10     // left sensor
#define Right_S 8      // right sensor
#define Forward_S 2 //forward sensor

/*-------defining Outputs------*/
#define LM1 3       // left motor
#define LM2 5       // left motor
#define RM1 6       // right motord
#define RM2 9       // right motor
#define pump 7

void setup()
{
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);

  myservo.attach(12); //servo attached at 12 pin
  myservo.write(90);
}

void put_off_fire_forward()
{
  //delay (500);

    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);

     digitalWrite(pump, HIGH);
     delay(500);

    for (pos = 50; pos <= 130; pos += 1) {
      myservo.write(pos);
      delay(20);
    }
    for (pos = 130; pos >= 50; pos -= 1) {
      myservo.write(pos);
      delay(20);
    }

    digitalWrite(pump,LOW);
   myservo.write(90);

   fire=false;
}
void put_off_fire_right()
{
  //delay (500);

    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
     myservo.write(30);

    digitalWrite(pump, HIGH);
     delay(500);
    for (pos = 0; pos <= 60; pos += 1) {
      myservo.write(pos);
      delay(20);
    }
    for (pos = 60; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(20);
    }

    digitalWrite(pump,LOW);
   myservo.write(90);

   fire=false;
}
void put_off_fire_left()
{
  //delay (500);

    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
     myservo.write(150);

     digitalWrite(pump, HIGH);
     delay(500);
    for (pos = 120; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(20);
    }
    for (pos = 180; pos >= 120; pos -= 1) {
      myservo.write(pos);
      delay(20);
    }

    digitalWrite(pump,LOW);
    myservo.write(90);

   fire=false;
}
void right_move(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    analogWrite(RM1, 150);
    digitalWrite(RM2, LOW);
    fire = true;
}
void left_move(){
    analogWrite(LM1, 150);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    fire = true;
}
void forward_move(){
    analogWrite(LM1, 100);
    digitalWrite(LM2, LOW);
    analogWrite(RM1, 100);
    digitalWrite(RM2, LOW);
    fire = true;
}
void loop()
{
   myservo.write(90); //Sweep_Servo();

    if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero
    {
    //Do not move the robot
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    }

    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead
    {
    //Move the robot forward
    forward_move();
    delay(500); //Slow down the speed of robot

     while (fire == true)
     {
      put_off_fire_forward();
     }
    }

    else if (digitalRead(Left_S) ==0) //If Fire is to the left
    {
    //Move the robot left
      left_move();
      delay(500); //Slow down the speed of robot

     while (fire == true)
     {
      put_off_fire_left();
     }
    }

    else if (digitalRead(Right_S) ==0) //If Fire is to the right
    {
    //Move the robot right
      right_move();
      delay(500); //Slow down the speed of robot

     while (fire == true)
     {
      put_off_fire_right();
     }
    }
}
