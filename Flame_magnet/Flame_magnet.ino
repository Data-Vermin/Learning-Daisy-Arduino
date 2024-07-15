/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
int flame;
int magnet;
int dail;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  D1 = analogRead(A0);
  D2 = analogRead(A1);
  D3 = analogRead(A2);
  D4 = analogRead(A3);

  B1 = digitalRead(D1);
  B2 = digitalRead(D2);
  B3 = digitalRead(D3);
  B4 = digitalRead(D4);

  SW1 = digitalRead(D5);
  SW2 = digitalRead(D6);
  SW3 = digitalRead(D7);
  SW4 = digitalRead(D8);
  SW5 = digitalRead(D9);
  SW6 = digitalRead(D10);
  SW7 = digitalRead(D11);
  SW8 = digitalRead(D12);

  // print out the value you read:
  Serial.print("A*");
  Serial.println(D1);

  Serial.print("B*");
  Serial.println(D2);

  Serial.print("C*");
  Serial.println(D3);

  Serial.print("D*");
  Serial.println(D4);

  Serial.print("E*");
  Serial.println(B1);

  Serial.print("F*");
  Serial.println(B2);

  Serial.print("G*");
  Serial.println(B3);

  Serial.print("H*");
  Serial.println(B4);

  Serial.print("I*");
  Serial.println(SW1);

  Serial.print("J*");
  Serial.println(SW2);

  Serial.print("K*");
  Serial.println(SW3);

  Serial.print("L*");
  Serial.println(SW4);

  Serial.print("M*");
  Serial.println(SW5);

  Serial.print("N*");
  Serial.println(SW6);

  Serial.print("O*");
  Serial.println(SW7);

  Serial.print("P*");
  Serial.println(SW8);

  delay(20);  // delay in between reads for stability
}
