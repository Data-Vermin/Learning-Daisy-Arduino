#include <Keyboard.h>

const int switch5Pin = 5; 
bool programRunning = false;

void setup() {
  pinMode(switch5Pin, INPUT);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(switch5Pin) == HIGH && !programRunning) { // Check if the switch is pressed and the program is not running
    delay(100); // Debounce delay
    if (digitalRead(switch5Pin) == HIGH) { // Check again to avoid false positives
      // Simulate pressing Windows key and typing the program name, then pressing Enter
      Keyboard.press(KEY_LEFT_GUI);
      delay(100); // Give the system some time to recognize the keypress
      Keyboard.press('r');
      Keyboard.releaseAll();
      delay(1000); // Wait for the Run dialog to open
      Keyboard.print("notepad.exe"); // Replace "notepad.exe" with the program you want to open
      delay(100); // Give the system some time to type
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      programRunning = true; // Set the programRunning flag to true
    }
  } else if (digitalRead(switch5Pin) == LOW && programRunning) { // Check if the switch is released and the program is running
    delay(100); // Debounce delay
    if (digitalRead(switch5Pin) == LOW) { // Check again to avoid false positives
      // Simulate pressing Alt + F4 to close the program
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      delay(100); // Give the system some time to recognize the keypress
      Keyboard.releaseAll();
      programRunning = false; // Set the programRunning flag to false
    }
  }
}
