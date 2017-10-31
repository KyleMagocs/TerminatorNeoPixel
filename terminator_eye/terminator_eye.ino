#include <Adafruit_NeoPixel.h>

#define PIN            1
#define NUMPIXELS      1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(250, 0, 0)); 
  pixels.show(); 
  delay(15000); 

  fade_out();
  delay(3000);
  blink_light(1);
  delay(500);
  blink_light(3);
  delay(3000);
  fade_in();
}

void fade_out() {
  float in, out;
  for (in = 6.283; in > 4.712; in = in - 0.001)
  {
    out = sin(in) * 127.5 + 127.5;
    pixels.setPixelColor(0, pixels.Color(out, 0, 0)); 
    pixels.show();
    delay(1);
  }
}

void fade_in() {
  float in, out;
  for (in = 4.712; in < 6.283; in = in + 0.002)
  {
    out = sin(in) * 127.5 + 127.5;
    pixels.setPixelColor(0, pixels.Color(out, 0, 0));
    pixels.show(); 
    delay(1);
  }
}

void blink_light(int reps) {
  for (int i = 0; i < reps; i++)
  {
    pixels.setPixelColor(0, pixels.Color(250, 0, 0));
    pixels.show(); 
    delay(100); 
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    delay(100);
  }
}

