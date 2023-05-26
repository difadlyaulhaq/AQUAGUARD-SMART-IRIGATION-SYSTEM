#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int SensorPin = A0;
int data;

int motorPin = 5; // Pin D5 for the motor
int ledPin = 6;   // Pin D6 for the LED

void setup() {
  lcd.begin(20, 4);
  lcd.setCursor(0, 1);
  lcd.print("-------SENSOR-------");
  lcd.setCursor(2, 2);
  lcd.print("KELEMBABAN");

  pinMode(motorPin, OUTPUT); // Initialize motor pin as output
  pinMode(ledPin, OUTPUT);   // Initialize LED pin as output
}

void loop() {
  data = analogRead(SensorPin);
  float Kelembaban = analogRead(SensorPin) * 0.0981354269; // sinyal analog sensor (1019)dirubah ke persen (100:1019)

  lcd.setCursor(13, 2);
  lcd.print(Kelembaban);
  lcd.print("%");

  // Check if Kelembaban is less than 500
  if (Kelembaban < 500) {
    digitalWrite(ledPin, LOW); // Turn off the LED
    digitalWrite(motorPin, LOW); // Deactivate the motor
    delay(2000); // Delay for 2 seconds
  }
  else {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    digitalWrite(motorPin, HIGH); // Activate the motor
    delay(2000); // Delay for 2 seconds
  }
}
