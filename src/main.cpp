#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address (adjust based on your LCD screen)
#define LCD_ADDRESS 0x27

// Set the LCD columns and rows
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Create an instance of the LiquidCrystal_I2C library
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
int lightValue = analogRead(A0);

void setup() {
  // Setup serial communication at baudrate 9600 for reading the light sensor
  Serial.begin(9600);

  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight (if your LCD has backlight control)
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  delay(10000);
}

void loop() {
  // Reads the input on analog pin A0
  int lightValue = analogRead(A0);

  // Print out the values to read in the Serial Monitor
  Serial.print("Analog reading (0-1023): ");
  Serial.print(lightValue);

  // Use the value to determine how dark it is 
  // (Try tweaking these to make it more accurate)
  if (lightValue < 10) {
    lcd.clear();
    lcd.print("Dark");
  } else if (lightValue < 200) {
    lcd.clear();
    lcd.print("Dim");
  } else if (lightValue < 500) {
    lcd.clear();
    lcd.print("Light");
  } else if (lightValue < 800) {
    lcd.clear();
    lcd.print("Bright");
  } else {
    lcd.clear();
    lcd.print("Very bright");
  }

  delay(500);
}
