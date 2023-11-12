/*This code will read a resistance and print it onto an lcd.*/
#include <LiquidCrystal.h>  //allow the library for the lcd to be enabled
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // connect pins to arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // idnetify the pins 
byte omega[] = {  //These next lines creat the omega symbol
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011
};
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); //identify the size of the screen 
lcd.createChar(0, omega); //creat our custom character
analogRead(A0); //define A0 as an input
}
void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0); // identify start point
float voltage = analogRead(A0) * (5.0/1023.0); // create equations for voltage
float current = (5 - voltage)/1000; // create equatsion for current
float resistance = (voltage/current); // create equation for resistnace
lcd.print(resistance); //print resistance
lcd.write(byte(0)); //pirnt custom omega value
}











