

#define PIN 26


#define PIEZO_PIN_1 36
#define PIEZO_PIN_2 39
#define PIEZO_PIN_3 34
#define PIEZO_PIN_4 35
#define PIEZO_PIN_5 32
#define PIEZO_PIN_6 33
#define PIEZO_PIN_7 25
int Nuberthing = 1520;
int timer;
bool sentTrigger = false;
bool trigger = false;

void setup() {
  Serial.begin(9600); 
  pinMode(12, OUTPUT);

}

void loop() {
  // Read the analog values from the piezo buzzers
  int sensorValue1 = analogRead(PIEZO_PIN_1);
  int sensorValue2 = analogRead(PIEZO_PIN_2);
  int sensorValue3 = analogRead(PIEZO_PIN_3);
  int sensorValue4 = analogRead(PIEZO_PIN_4);
  int sensorValue5 = analogRead(PIEZO_PIN_5);
  int sensorValue6 = analogRead(PIEZO_PIN_6);
  int sensorValue7 = analogRead(PIEZO_PIN_7);
  
  // Print the sensor values to the serial monitor
  Serial.print("Sensor 1: ");
  Serial.println(sensorValue1);
  // Serial.println("Sensor 2: ");
  // Serial.print(sensorValue2);
  // Serial.println("Sensor 3: ");
  // Serial.print(sensorValue3);
  // Serial.println("Sensor 4: ");
  // Serial.print(sensorValue4);
  // Serial.println("Sensor 5: ");
  // Serial.print(sensorValue5);
  // Serial.println("Sensor 6: ");
  // Serial.print(sensorValue6);
  // Serial.println("Sensor 7: ");
  // Serial.print(sensorValue7);
timer++;

if(sensorValue1 > Nuberthing || sensorValue2 > Nuberthing || sensorValue3 > Nuberthing || sensorValue4 > Nuberthing || sensorValue5 > Nuberthing || sensorValue6 > Nuberthing || sensorValue7 > Nuberthing){
  if(!sentTrigger){
    timer = 0;
    //Serial.println("sending trigger");
    trigger = true;
    sentTrigger = true;
  }
}
if(timer > 500){
  trigger = false;
  Serial.println("ending trigger");
  sentTrigger = false;  
}
if(trigger){
  Serial.println("sending high");
  digitalWrite(12, HIGH);
}else{
  Serial.println("sending low");
  digitalWrite(12, LOW);
}



 delay(10); // Wait for 1 second before reading again
}
