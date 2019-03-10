/* This code controls a mini Traffic light junction
and displays to the LCD display */

#include <LiquidCrystal.h>
int red = 7;
int yellow = 1;
int green = 0;
int piezoPin = 8;
const int rs = 12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    tone(piezoPin,1000, 50);
    lcd.begin(16, 2); //Row by Column
    lcd.print("Traffic Light!");
}


void loop() {
 lcd.setCursor(0, 1); //Set cursor to column 0, line 1
 lcd.print("By Krish&Jia Hao!");
 changeLights();
 delay(12000);

}

void changeLights(){
    // green off, yellow on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Prepare to stop!");
    tone(piezoPin,1000, 50);
    delay(3000);

    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Red Light! Stop!");
    tone(piezoPin, 3000, 500);
    delay(4000);

    // red and yellow on for 2 seconds (red is already on though)
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Get ready to go!");
    delay(2000);

    // turn off red and yellow, then turn on green
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Green Light! Go!");
    tone(piezoPin, 1500, 50);
    delay(3000);
}
