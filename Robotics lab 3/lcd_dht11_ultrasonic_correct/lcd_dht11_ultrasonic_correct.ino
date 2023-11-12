/* The purpose of this code is to read the temperature and humidity from a dht11 sensor, aswell as the distance of an object with the ultrasonic sensor. 
I will display the distnace, but when a button is pushed the humidity and temperature will be displayed*/
#include "dht.h"  // include the libabary for our dht11
#define dht_apin A0 //idenitfya variable for pin A0
dht DHT; //define dht
#include <LiquidCrystal.h>  //include the library for our lcd
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //define pins for lcd
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //activate pins of the lcd
#define trigPin 10 // identify the trig pin for the ultrasonic 
#define echoPin 13 // identify echo pin for ultrasonic sensor
float duration, distance; // allows our ultrasonic sensor to display decimal values
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //identify a bit value
lcd.begin(16,2);  //identify the size of the screen
pinMode(trigPin, OUTPUT); // idenitfy trig pin as output
pinMode(echoPin, INPUT); // identify echopin as output 
analogRead(A1); // identify pin a1 as an input
delay(500);    //delay for half a second
}
void loop() { 
  float sensorValue = analogRead(A1); //identify a variable for analogRead
  float Voltage = sensorValue * (5.0 / 1023.0); // convert bitvalue to a voltage
   if(4 > Voltage >=  0){ // the following action will only occur if voltrage is between 0 and less than 4 (button unpressed)
    DHT.read11(dht_apin); //read from analog pin A0
    lcd.setCursor(0,0); // determine the coordinate for the writing to start
    lcd.print("humidity = "); // write humidity before the actual value so we dont get confused
    lcd.print(DHT.humidity); //display the humidity value
    lcd.print("%  "); // display a percentage symbol after the humidity
    lcd.setCursor(0,-1); //begin the temperature reading on the bottom column
    lcd.print("temp = "); // write temp so we dont get confused
    lcd.print(DHT.temperature); // display the temperature
    lcd.print("C  "); // c for celcius so we dont confuse our units
     
  }
  if(Voltage >=4){ //this will only occur if voltage is greater than or equal to 4 (button pressed)
   lcd.setCursor(0,0); // tells the lcd where to begin
digitalWrite(trigPin, LOW); // turns off trig pin
delayMicroseconds(2); //delays for 2 micro seconds
digitalWrite(trigPin, HIGH); // turns on trigpin
delayMicroseconds(10); // delays for 10 micro seconds
digitalWrite(trigPin,LOW); // turn off trigPin
duration = pulseIn(echoPin, HIGH); //identify parameter for duration
distance = (duration / 2) * 0.0343; //create formula to calculate distance
 lcd.clear(); //clear lcd to avoid over lapping
  lcd.setCursor(0,0); //tells the lcd where to begin
  lcd.print("Distance = "); //physically prints the word distance so we know what we are talking about
  lcd.setCursor(0, -1); //tells the lcd where to send the following writing
  lcd.print(distance); //prints the calculated distance
  lcd.print(" CM"); //prints out cm so we are familiar with out units
   }
   Serial.println(Voltage); // shows our voltage so we can measure it to trouble shoot and issue with the pushbutton. 

}
