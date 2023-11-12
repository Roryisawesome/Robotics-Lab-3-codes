/* The purpose of this code is to read the temperature and humidity from a dht11 sensor
and have it display on an lcd*/
#include "dht.h"  // include the libabary for our dht11
#define dht_apin A0 //idenitfya variable for pin A0
dht DHT; //define dht
#include <LiquidCrystal.h>  //include the library for our lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //define pins for lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //activate pins of the lcd

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //identify a bit value
lcd.begin(16,2);  //identify the size of the screen
delay(500);    //delay for half a second
 
  
}
void loop() {
   DHT.read11(dht_apin); //read from analog pin A0
    lcd.setCursor(0,0); // determine the coordinate for the writing to start
    lcd.print("humidity = "); // write humidity before the actual value so we dont get confused
    lcd.print(DHT.humidity); //display the humidity value
    lcd.println("%  "); // display a percentage symbol after the humidity
   lcd.setCursor(0,-1); //begin the temperature reading on the bottom column
    lcd.print("temp = "); // write temp so we dont get confused
    lcd.print(DHT.temperature); // display the temperature
    lcd.print("C  "); // c for celcius so we dont confuse our units
    delay(50); //delay for 5 seconds
  

}
