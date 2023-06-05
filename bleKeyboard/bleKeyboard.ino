/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

// #define BUTTON1 21  // GIOP21 pin connected to button
#define LEFT 4
#define UP 16
#define RIGHT 17
#define R 15
#define L 2
#define DOWN 0

void setup() {

  pinMode(LEFT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    // bleKeyboard.write(KEY_RETURN);

    if (digitalRead(LEFT) == LOW) {
      bleKeyboard.press(KEY_LEFT_ARROW);
    } else {
      bleKeyboard.release(KEY_LEFT_ARROW);
    }

    if (digitalRead(UP) == LOW) {
      bleKeyboard.press(KEY_UP_ARROW);
    } else {
      bleKeyboard.release(KEY_UP_ARROW);
    }

    if (digitalRead(RIGHT) == LOW) {
      bleKeyboard.press(KEY_RIGHT_ARROW);
    } else {
      bleKeyboard.release(KEY_RIGHT_ARROW);
    }

    if (digitalRead(R) == LOW) {
      bleKeyboard.press(KEY_F1);
    } else {
      bleKeyboard.release(KEY_F1);
    }

    if (digitalRead(L) == LOW) {
      bleKeyboard.press(KEY_F2);
    } else {
      bleKeyboard.release(KEY_F2);
    }

    if (digitalRead(DOWN) == LOW) {
      bleKeyboard.press(KEY_DOWN_ARROW);
    } else {
      bleKeyboard.release(KEY_DOWN_ARROW);
    }
    
   //
   // Below is an example of pressing multiple keyboard modifiers 
   // which by default is commented out. 
   // 
   /* Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */

  }
}