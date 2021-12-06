// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            D6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      45

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

double multiplierStep = 0.003;
double multiplier = -multiplierStep;
int lightPause = 4000;
int cycleDelay = 10;
double intensity = 0;
double maxIntensity = 0.9;

int red = 0xFF;
int green = 0x45;
int blue = 0x05;

void setup() {
  Serial.println("LI MORTANGUERIERI");
  pixels.begin(); // This initializes the NeoPixel library.
}


void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){// Moderately bright green color.
    pixels.setPixelColor(i, pixels.Color(
      (int)(red * intensity),
      (int)(green * intensity),
      (int)(blue * intensity)));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

  intensity += multiplier;
  if (intensity >= maxIntensity) {
    multiplier = -multiplierStep;
    intensity = maxIntensity;
    delay(lightPause);
  } else if (intensity < 0) {
    multiplier = multiplierStep;
    intensity = 0;
    delay(lightPause);
  }
  delay(cycleDelay);
}
