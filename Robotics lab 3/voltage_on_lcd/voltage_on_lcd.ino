/* This code tells the arduino micro controller to read a bitvalue, convert it into a voltage value 
between 0-5 and display this value on an lCD display. */

#include <LiquidCrystal.h> //includes the library required to make the lcd function
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //connect the pins from arduino to the LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //assign the pins to the arduino from the LCD
void setup() {
  // put your setup code here, to run once:
analogRead(A0); //define A0 as an input
Serial.begin(9600);  //allow our bitvalue to exists

lcd.begin(16, 2); //identify the x and y coordinates of our lcd display


}

void loop() {
 lcd.setCursor(1,0); //identify an x and y component to begin the display. 
  lcd.print("VOLTAGE = "); //this will prin "Voltage" on to the screen so that we know what vaue is being displayed
  float voltage = analogRead(A0) * (5.0/1023.0); // convert the bitvalue into a voltage value
  lcd.print(voltage); //print value onto the lcd display
   

}
