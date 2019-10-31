//pin declaration
const int trigPin = 9;
const int echoPin = 10;

#define M2 3
#define M1 5

//variable declaration
float duration;
float distance;

void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  Serial.begin(9600);
}

void calculate(){
   digitalWrite(trigPin, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(15);
   digitalWrite(trigPin, LOW);

   duration = pulseIn(echoPin, HIGH);
   distance = (duration*(.0343))/2;
}

void loop(){
  calculate();
  Serial.println(distance);
  if(distance<=20){
    analogWrite(M1,120);
    digitalWrite(M2,LOW);
    delay(400); 
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
    calculate(); 
     while(distance<=20)
        calculate(); 
  
    calculate();
    Serial.println(distance);
     if(distance>20){
      digitalWrite(M1,LOW);
      analogWrite(M2,150);
      delay(400);
     digitalWrite(M1,LOW);
    digitalWrite(M2,LOW); 
  }
}
  //delay(100);
}
