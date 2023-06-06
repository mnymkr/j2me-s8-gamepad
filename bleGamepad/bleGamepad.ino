/*
 * This example turns the ESP32 into a Bluetooth LE gamepad that presses buttons and moves axis
 *
 * At the moment we are using the default settings, but they can be canged using a BleGamepadConfig instance as parameter for the begin function.
 *
 * Possible buttons are:
 * BUTTON_1 through to BUTTON_16
 * (16 buttons by default. Library can be configured to use up to 128)
 *
 * Possible DPAD/HAT switch position values are:
 * DPAD_CENTERED, DPAD_UP, DPAD_UP_RIGHT, DPAD_RIGHT, DPAD_DOWN_RIGHT, DPAD_DOWN, DPAD_DOWN_LEFT, DPAD_LEFT, DPAD_UP_LEFT
 * (or HAT_CENTERED, HAT_UP etc)
 *
 * bleGamepad.setAxes sets all axes at once. There are a few:
 * (x axis, y axis, z axis, rx axis, ry axis, rz axis, slider 1, slider 2)
 *
 * Library can also be configured to support up to 5 simulation controls
 * (rudder, throttle, accelerator, brake, steering), but they are not enabled by default.
 *
 * Library can also be configured to support different function buttons
 * (start, select, menu, home, back, volume increase, volume decrease, volume mute)
 * start and select are enabled by default
 */

#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad bleGamepad;
BleGamepadConfiguration bleGamepadConfig;
#define numOfButtons 64

#define DOWN 0
#define LEFT 4
#define UP 16
#define RIGHT 17
#define R 15
#define L 2
#define STAR 13
#define ONE 12
#define FOUR 14
#define SEVEN 27
#define ZERO 26
#define TWO 25
#define FIVE 33
#define EIGHT 22
#define HASHTAG 19
#define THREE 21
#define SIX 5
#define NINE 18

void setup()
{
    pinMode(LEFT, INPUT_PULLUP);
    pinMode(UP, INPUT_PULLUP);
    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(R, INPUT_PULLUP);
    pinMode(L, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);
    pinMode(STAR, INPUT_PULLUP);
    pinMode(ZERO, INPUT_PULLUP);
    pinMode(HASHTAG, INPUT_PULLUP);
    pinMode(ONE, INPUT_PULLUP);
    pinMode(TWO, INPUT_PULLUP);
    pinMode(THREE, INPUT_PULLUP);
    pinMode(FOUR, INPUT_PULLUP);
    pinMode(FIVE, INPUT_PULLUP);
    pinMode(SIX, INPUT_PULLUP);
    pinMode(SEVEN, INPUT_PULLUP);
    pinMode(EIGHT, INPUT_PULLUP);
    pinMode(NINE, INPUT_PULLUP);

    int min = bleGamepadConfig.getAxesMin();
    int max = bleGamepadConfig.getAxesMax();

    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    bleGamepadConfig.setButtonCount(numOfButtons);
    bleGamepadConfig.setControllerType(CONTROLLER_TYPE_GAMEPAD);
    bleGamepadConfig.setWhichSpecialButtons(true, true, true, true, true, true, true, true);
    bleGamepad.begin(&bleGamepadConfig);
    // The default bleGamepad.begin() above enables 16 buttons, all axes, one hat, and no simulation controls or special buttons
}

void loop()
{
    if (bleGamepad.isConnected())
    {
    if (digitalRead(LEFT) == LOW) {
      bleGamepad.press(BUTTON_15);
      // bleGamepad.setHat1(DPAD_LEFT);
    } else {
      bleGamepad.release(BUTTON_15);
      // bleGamepad.setHat1(DPAD_CENTERED);
    }

    if (digitalRead(UP) == LOW) {
      bleGamepad.press(BUTTON_16);
    } else {
      bleGamepad.release(BUTTON_16);
    }

    if (digitalRead(RIGHT) == LOW) {
      bleGamepad.press(BUTTON_19);
    } else {
      bleGamepad.release(BUTTON_19);

    }

    if (digitalRead(DOWN) == LOW) {
      bleGamepad.press(BUTTON_17);
    } else {
      bleGamepad.release(BUTTON_17);
    }

    if (digitalRead(R) == LOW) {
      bleGamepad.press(BUTTON_1);
    } else {
      bleGamepad.release(BUTTON_1);
    }

    if (digitalRead(L) == LOW) {
      bleGamepad.press(BUTTON_2);
    } else {
      bleGamepad.release(BUTTON_2);
    }

    if (digitalRead(STAR) == LOW) {
      bleGamepad.press(BUTTON_3);
    } else {
      bleGamepad.release(BUTTON_3);
    }

    if (digitalRead(ZERO) == LOW) {
      bleGamepad.press(BUTTON_4);
    } else {
      bleGamepad.release(BUTTON_4);
    }

    if (digitalRead(HASHTAG) == LOW) {
      bleGamepad.press(BUTTON_5);
    } else {
      bleGamepad.release(BUTTON_5);
    }

    if (digitalRead(ONE) == LOW) {
      bleGamepad.press(BUTTON_6);
    } else {
      bleGamepad.release(BUTTON_6);
    }

    if (digitalRead(TWO) == LOW) {
      bleGamepad.press(BUTTON_7);
    } else {
      bleGamepad.release(BUTTON_7);
    }

    if (digitalRead(THREE) == LOW) {
      bleGamepad.press(BUTTON_8);
    } else {
      bleGamepad.release(BUTTON_8);
    }

    if (digitalRead(FOUR) == LOW) {
      bleGamepad.press(BUTTON_9);
    } else {
      bleGamepad.release(BUTTON_9);
    }

    if (digitalRead(FIVE) == LOW) {
      bleGamepad.press(BUTTON_10);
    } else {
      bleGamepad.release(BUTTON_10);
    }

    if (digitalRead(SIX) == LOW) {
      bleGamepad.press(BUTTON_11);
    } else {
      bleGamepad.release(BUTTON_11);
    }

    if (digitalRead(SEVEN) == LOW) {
      bleGamepad.press(BUTTON_12);
    } else {
      bleGamepad.release(BUTTON_12);
    }

    if (digitalRead(EIGHT) == LOW) {
      bleGamepad.press(BUTTON_13);
    } else {
      bleGamepad.release(BUTTON_13);
    }

    if (digitalRead(NINE) == LOW) {
      bleGamepad.press(BUTTON_14);
    } else {
      bleGamepad.release(BUTTON_14);
    }

  }
}
