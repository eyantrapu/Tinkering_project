#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int joystick1x = A1;
int joystick1y = A0;
int joystick2x = A4;
int joystick2y = A5;
void setup() {
  // put your setup code here, to run once:
servo1.attach(3);
servo2.attach(5);
servo3.attach(6);
servo4.attach(9);
pinMode(joystick1x,INPUT);
pinMode(joystick1y,INPUT);
pinMode(joystick2x,INPUT);
pinMode(joystick2y,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
int val1 = analogRead(joystick1x);
int valx1 = map(val1,0,1023,0,180);
servo1.write(valx1);
delay(11);
int val2 = analogRead(joystick1y);
int valy1 = map(val2,0,1023,0,180);
servo2.write(valy1);
delay(11);
int val3 = analogRead(joystick2x);
int valx2 =map(val3,0,1023,0,180);
servo3.write(valx2);
delay(11);
int val4 = analogRead(joystick2y);
int valy2 = map(val4,0,1023,0,180);
servo4.write(valy2);
delay(11);
}

