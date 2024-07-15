 #include <Adafruit_NeoPixel.h>

// Define the pin for the NeoPixel data line
#define PIN 6
#define TRIGPIN 7
bool trigger = false;

// Define the number of NeoPixels
//#define NUMPIXELS 200

// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel pixels(300, PIN, NEO_GRB + NEO_KHZ800);

// Define the color of the pulse (red in this case)
//uint32_t pulseColor = pixels.Color(255, 0, 0);

// Define the delay between updates
int delayTime = 0;

void setup() {
  pinMode(TRIGPIN, INPUT);
  // Initialize the NeoPixel strip
  pixels.begin();
  pixels.show(); // Initialize all pixels to 'off'
  pixels.setBrightness(50);
}

void loop() {

  trigger = digitalRead(TRIGPIN);
  Serial.println(trigger);

  uint32_t pulseColor = pixels.Color(200, 50, 255);
  
  for (int i = 0; i < pixels.numPixels(); i++) {
    // Set the current pixel to the pulse color
    pixels.setPixelColor(i, pulseColor);

    // Dim the previous pixels
    for (int j = 0; j < i; j++) {
      uint32_t color = pixels.getPixelColor(j);
      uint8_t r = (color >> 16) & 0xFF;
      uint8_t g = (color >> 8) & 0xFF;
      uint8_t b = color & 0xFF;

      // Dim the color by reducing its brightness
      r = r * 0.8;
      g = g * 0.8;
      b = b * 0.8;

      // Set the dimmed color
      pixels.setPixelColor(j, pixels.Color(r, g, b));
    }

    // Show the updated colors
    if(trigger){
      pixels.show();
    }

    // Wait before moving to the next pixel
    delay(delayTime);
  }
}
