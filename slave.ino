//slave
#include <Wire.h>

int LED = 13;
int x = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent(int bytes) {
  if (Wire.available()) {
    x = Wire.read();// х отримує значенння(контролюється зовнішнім пристроєм)
  }
}

void loop() {
  analogWrite(LED, x); 
  Serial.print("Writing to led: ");
  Serial.println(x);
  delay(100);
}