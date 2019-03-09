#include<LiquidCrystal.h>
const int ir_in=10;
const int ir_out=11;
const int buzzer=9;
int in_high;
int out_high;
int total_people=0;
LiquidCrystal lcd(13,12,7,6,5,4);
void setup() 
{
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ir_in,INPUT);
  pinMode(ir_out,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  in_high=digitalRead(ir_in);
  out_high=digitalRead(ir_out);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("People_IN:");
  lcd.setCursor(0,1);
  lcd.print("People_OUT:");
  if(in_high == HIGH)
  {
    total_people+=1;
    lcd.setCursor(10,0);
    lcd.print(total_people);
    Serial.print("IN");
    Serial.println(total_people);
  }
  else if(out_high == HIGH)
  {
    total_people-=1;
    lcd.setCursor(11,1);
    lcd.print(total_people);
    Serial.print("Left");
    Serial.println(total_people);
  }
  if(total_people==10)
  {
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Capacity Full");
  }
  delay(3000);
}
