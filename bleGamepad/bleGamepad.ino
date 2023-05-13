#include <BleGamepad.h>
BleGamepad bleGamepad;

#define BUTTON1 21  // GIOP21 pin connected to button

int button1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  bleGamepad.begin();

  pinMode(BUTTON1, INPUT_PULLUP);
}

void loop() {
  button1 = digitalRead(BUTTON1);

  if (button1 == LOW) {
    bleGamepad.press(BUTTON_1);
    Serial.write("Pressing button 1\n");
  } else {
    bleGamepad.release(BUTTON_1);
    Serial.write("Releasing button 1\n");
  }
  
}
