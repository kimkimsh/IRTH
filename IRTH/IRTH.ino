/* 
I used two baisic example of library to write the code
one is 'Helloworld' example of 'Arduino-LiquidCrystal-I2C-library'
and other is 'singleDevice' example of 'Digital_Infrared_Temperature_Sensor_MLX90615'
*/

//I used 'Arduino-LiquidCrystal-I2C-library', You can get it from here
// https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
#include "MLX90615.h"

#include <Wire.h>

//I used 'Digital_Infrared_Temperature_Sensor_MLX90615', You can get it from here
// https://github.com/Seeed-Studio/Digital_Infrared_Temperature_Sensor_MLX90615
#include <LiquidCrystal_I2C.h>

#define MLX MLX90615_DefaultAddr

//(I2C address, chars, lines), put in your device's own
LiquidCrystal_I2C lcd(0x27, 16, 2);

MLX90615 mlx90615(MLX, &Wire);

void setup() {
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  
  float temperatureObj = mlx90615.getTemperature(MLX90615_OBJECT_TEMPERATURE);
  float temperatureAmb = mlx90615.getTemperature(MLX90615_AMBIENT_TEMPERATURE);
  
  Serial.print("Temp_1: ");
  Serial.print(temperatureObj);
  Serial.println("°C  ");
  Serial.print("Temp_2: ");
  Serial.print(temperatureAmb);
  Serial.println("°C  ");
  
  Serial.println("\n=======================================\n\r");

  lcd.setCursor(2,0);
  lcd.print("Obj : ");
  lcd.print(temperatureObj);
  lcd.print(" C ");
  lcd.setCursor(2,1);
  lcd.print("Amb : ");
  lcd.print(temperatureAmb);
  lcd.print(" C ");

  delay(500);
}
