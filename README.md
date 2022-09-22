# TMU-CanSat-Software-Training-Package
## By: Mishran Haque
The following code is developed as a part of the TMU Cansat 2022-2023 new members training task.  
  
The ardunio circuit consists of Arduino Uno, TMP36 Temperature Sensor, RGB LED, and Servo Motor.  
  
![Circuit](https://user-images.githubusercontent.com/64446677/191836927-391effd3-6da7-4e61-895e-ca56cc041f5c.PNG)   
  
The software reads the voltage from the temperature sensor and converts the reading into a temperature value. This reading is then assigned to an RGB colour code based on the following table.  
  
| Temperature Range  | Colour |
| ------------- | ------------- |
| -40 <= Temp <= -10  | Blue  |
| -10 < Temp <= 20  | Green  |
| 20 < Temp <= 50  | Yellow  |
| 50 < Temp <= 80  | Purple |
| 80 < Temp <= 110  | Red |
| 110 < Temp <= 125  | White |
  
  
Alongside this, the temperature value is mapped to the servo motor's angle. This means that the maximum and the minimum value of the temperature sensor (-40 to 125) is mapped to the minimum and maximum angle of the servo motor (0 to 180). The angle of the servo motor is then written based on the temperature reading.

