#include <Wire.h>
int buttonPin = 15; 
int buttonState = 0;
int ledValue = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin); 
  Serial.print(123);
  if (buttonState == LOW) {
    ledValue = 255;
  } else {
    ledValue = 0;
  }
  Serial.print("Button state: ");
  Serial.print(buttonState);
  Serial.print(", Sending value: ");
  Serial.println(ledValue);
  Wire.beginTransmission(9);
  Wire.write(ledValue); 
  Wire.endTransmission(); 
  delay(50); 
}