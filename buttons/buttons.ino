#include <Keyboard.h>

// use this option for OSX:
// char ctrlKey = KEY_LEFT_GUI;
// use this option for Windows and Linux:
char ctrlKey = KEY_LEFT_CTRL;
char shiftKey = KEY_LEFT_SHIFT;
char altKey = KEY_LEFT_ALT;

const int switch5Pin = 5; 
const int switch6Pin = 6;
const int switch7Pin = 7;
const int switch8Pin = 8;
const int switch9Pin = 9; 
const int switch10Pin = 10;
const int switch11Pin = 11;
const int switch12Pin = 12;
bool programRunning = false;

// Define the pins for your buttons
const int button1Pin = 1;
const int button2Pin = 2;
const int button3Pin = 3;
const int button4Pin = 4;

// Define the keys you want to emulate
const char key1 = 'a'; // Example: 'a' key
const char key2 = 'b'; // Example: 'b' key

void setup() {
  // Initialize the buttons as inputs
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
  pinMode(switch5Pin, INPUT);
  
  // Initialize the keyboard
  Keyboard.begin();
}

void loop() {
  // Read the state of buttons
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);
  int button4State = digitalRead(button4Pin);

  // If button 1 is pressed
  if (button1State == HIGH) {
    Keyboard.press(altKey);
    Keyboard.press(',');
    delay(100); // Adjust delay if necessary
    Keyboard.releaseAll();
  }
  
  // If button 2 is pressed
  if (button2State == HIGH) {
    Keyboard.press(altKey);
    Keyboard.press('.');
    delay(100); // Adjust delay if necessary
    Keyboard.releaseAll();

  }
  
  // If button 3 is pressed
  if (button3State == HIGH) {
    Keyboard.press(altKey);
    Keyboard.press('/');
    delay(100); // Adjust delay if necessary
    Keyboard.releaseAll();
  }
  
  // If button 4 is pressed
  if (button4State == HIGH) {
    Keyboard.press(altKey);
    Keyboard.press(';');
    delay(100); // Adjust delay if necessary
    Keyboard.releaseAll();
  }

  if (digitalRead(switch5Pin) == HIGH && !programRunning) { // Check if the switch is pressed and the program is not running
    delay(100); // Debounce delay
    if (digitalRead(switch5Pin) == HIGH) { // Check again to avoid false positives
      // Simulate pressing Windows key and typing the program name, then pressing Enter
      Keyboard.press(KEY_LEFT_GUI);
      delay(100); // Give the system some time to recognize the keypress
      Keyboard.press('r');
      Keyboard.releaseAll();
      delay(1000); // Wait for the Run dialog to open
      Keyboard.print("C:\Users\Eris\Desktop\Discord.lnk"); // Replace "notepad.exe" with the program you want to open
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
