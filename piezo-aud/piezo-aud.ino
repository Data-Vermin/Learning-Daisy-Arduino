#define PIEZO_PIN_1 A0 // Define the pin for the first piezo (analog pin A0)
#define PIEZO_PIN_2 A1 // Define the pin for the second piezo (analog pin A1)

void setup() {
  pinMode(PIEZO_PIN_1, OUTPUT); // Set the pin mode for the first piezo as output
  pinMode(PIEZO_PIN_2, OUTPUT); // Set the pin mode for the second piezo as output
}

void loop() {
  // Test the first piezo
  tone(PIEZO_PIN_1, 1000); // Emit a tone of 1000Hz on the first piezo
  delay(1000); // Wait for 1 second
  noTone(PIEZO_PIN_1); // Stop emitting tone on the first piezo
  
  // Test the second piezo
  tone(PIEZO_PIN_2, 1500); // Emit a tone of 1500Hz on the second piezo
  delay(1000); // Wait for 1 second
  noTone(PIEZO_PIN_2); // Stop emitting tone on the second piezo

  delay(1000); // Wait for 1 second before starting the test again
}
