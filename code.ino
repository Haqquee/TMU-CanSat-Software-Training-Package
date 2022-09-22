#include <Servo.h>

// C++ code
//

Servo servo;
int sensorPin = A0;
int redPin = 3;
int greenPin = 6;
int bluePin = 5;
int servoPin = 9;

void setup()
{
  
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  servo.attach(servoPin);
  
}

void loop()
{
  
  // Converting voltage reading into temperature in degrees C
  int reading = analogRead(sensorPin);
  float volt = reading * 5.0; volt /= 1024.0;
  float temp = (volt - 0.5) * 100;
  Serial.print("\nTemperature in degrees C = "); Serial.print(temp); 
  
  // Changing the RGB LED colour depening on the temperature
  // blue
  if (-40 <= temp && temp <= -10) {
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  }
  
  // green
  if (-10 < temp && temp <= 20) {
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    analogWrite(bluePin,0);
  }
  
  // yellow
  if (20 < temp && temp <= 50) {
    analogWrite(redPin,255);
    analogWrite(greenPin,255);
    analogWrite(bluePin,0);
  }
  
  // purple
  if (50 < temp && temp <= 80) {
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  }
  
  // red 
  if (80 < temp && temp <= 110) {
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,0);
  }
  
  // white
  if (110 < temp && temp <= 125) {
    analogWrite(redPin,255);
    analogWrite(greenPin,255);
    analogWrite(bluePin,255);
  }
  
  // The following are used as minimum and maximum values
  // minimum temperature = -40 degrees Celsius
  // maximum temperature = 125 degrees Celsius
  // minimum servo angle = 0 degrees
  // maximum servo angle = 180 degrees
  
  // mapping the servo motor angle to temp value
  float angle = map(temp, -40, 125, 0, 180);
  servo.write(angle);
  Serial.print("\nServo angle in degrees = "); Serial.print(angle);
 
  delay(1000);
  
}