#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define HSV_HUE_STEP 43
#define HSV_HUE_MIN  0
#define HSV_HUE_MAX  65535

#define LED_PIN   4
#define LED_COUNT 128

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void NeoPixels_Show()
{
  delay(1);
  portDISABLE_INTERRUPTS();
  strip.show();
  portENABLE_INTERRUPTS();
}

void setup() {
  strip.begin();
  strip.setBrightness(64); // 1/4 brightness
  strip.clear();
  strip.show();
}

void loop() {
  for(int hue = HSV_HUE_MIN; hue < HSV_HUE_MAX; hue += HSV_HUE_STEP)
  {
    strip.fill(strip.ColorHSV(hue), 0, 128);
    NeoPixels_Show();
    delay(5);
  }
}