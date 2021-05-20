//Prepared By: Rutika Mehta (mrutika16@gmail.com)

#include <LiquidCrystal.h>
#include <Wire.h>
#include <Servo.h>

int A1_exit = 15;
int A2_p = 16;
int A0_entry = 14;
int A3_p = 17;
int people = 0;

Servo servo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool pi = 0;
bool po = 0;
void setup() {
  pinMode(15, INPUT);
  pinMode(14, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
    
  // Servo motor is connected to D9
  servo.attach(9); 
  // Set the initial position of servo motor as 0 degrees.
  servo.write(0);
  lcd.begin(16, 2);
}

void loop() 
{
  lcd.clear();
  digitalWrite(A3_p, HIGH);
  digitalWrite(A2_p, HIGH);
  pi = digitalRead(A1_exit);
  po = digitalRead(A0_entry);
  if (pi == 1){
    people--;
    servo.write(90);
    delay(2000);
    servo.write(0);
  }
  else if (po == 1){
    if(people <= 4){
      people++;
      servo.write(90);
      delay(2000);
      servo.write(0);
    }
  }
  people = constrain(people, 0, 50);
  lcd.setCursor(0, 0);
  lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  lcd.print(people);
  if (people >= 5){
     lcd.setCursor(0, 5);
     lcd.print("ENTRY PROHIBITED");
     delay(1000);
  }
  if (people < 5){
     lcd.setCursor(0, 1);
     lcd.print("WELCOME!");
     delay(1000);
  }
}

 