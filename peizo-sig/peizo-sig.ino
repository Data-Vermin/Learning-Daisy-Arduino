#define PIEZO_PIN_1 A0 
#define PIEZO_PIN_2 A1 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // Read the analog values from the piezo buzzers
  int sensorValue1 = analogRead(PIEZO_PIN_1);
  int sensorValue2 = analogRead(PIEZO_PIN_2);
  
  // Print the sensor values to the serial monitor
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print(", Sensor 2: ");
  Serial.println(sensorValue2);

  delay(100); // Wait for 1 second before reading again
}
