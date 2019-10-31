/**DEFINING AND INITIALISING THE VARIABLES**/
              
  int trans = 2;
  int red_Led = 12;
  int yellowLed = 10;
  int buzzer = 3;
  int smokeA0 = A0;
  int sensorThres = 75;       // Your threshold value
/**setup routine **/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red_Led, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}
void loop() {
  int analogSensor;                   //variable taking input value 
  analogSensor= analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);       //print you read
  
 // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)    //smoke is detected
  {
    digitalWrite(LED_BUILTIN, HIGH);     //red led turns on
    pinMode(red_Led, HIGH);
    digitalWrite(yellowLed, LOW);    
    tone(buzzer, 1000, 200);        //buzzer starts beeping
    digitalWrite(trans,HIGH);         // motor starts
  Serial.println("high");       //print you read   
  }
  else                              // smoke not detected
  {
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(red_Led, LOW);
    digitalWrite(yellowLed, HIGH);   //green led turns on
    noTone(buzzer);
    delay(1000);
     digitalWrite(trans,LOW);
      Serial.println("low");       //print you read
  }
      delay(5000);                 //delay in between reads for stability
}

