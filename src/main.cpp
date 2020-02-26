#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "KpkDefines.h"

#define HSV_HUE_STEP 43
#define HSV_HUE_MIN  0
#define HSV_HUE_MAX  65535

Adafruit_NeoPixel strip(KPK_NEO_CNT, KPK_NEO_PIN, NEO_GRB + NEO_KHZ800);

/*!
 * @brief Get a pin index from the row and column
 * @param row Row number, 1-indexed
 * @param column Column number, 1-indexed
 * @return Neopixel index, 0-indexed
 */
int gridPin(int row, int column)
{
  int total = 0;
  total += (row - 1) * 16;
  total += (column - 1);
  return total;
}

void NeoPixels_Show()
{
  delay(1);
  portDISABLE_INTERRUPTS();
  strip.show();
  portENABLE_INTERRUPTS();
}

void DisplayProgram_Run()
{
  static int hue = HSV_HUE_MIN;
  if(hue >= HSV_HUE_MAX) {
    hue = HSV_HUE_MIN;
  }
  hue += HSV_HUE_STEP;

  strip.fill(strip.ColorHSV(hue), 0, 112);
}

void KnobProgram_Run()
{
  int input = analogRead(KPK_POT_PIN);
  int len = map(input, 0, 4095, 0, 16);

  // If 0 is passed to fill, it fills to end of strip
  if(len != 0)
  {
    strip.fill(strip.Color(255, 255, 255), 112, len);
  }
}

void ButtonProgram_Run()
{
  if(!digitalRead(KPK_BTN_B_PIN))
  {
    strip.setPixelColor(gridPin(2, 16), strip.Color(255, 255, 255));
  }

  if(!digitalRead(KPK_BTN_A_PIN))
  {
    strip.setPixelColor(gridPin(2, 14), strip.Color(255, 255, 255));
    // noTone(KPK_SPK_PIN);
    // tone(KPK_SPK_PIN, 440, 200);
  }

  if(!digitalRead(KPK_BTN_NONE_PIN))
  {
    strip.setPixelColor(gridPin(2, 9), strip.Color(255, 255, 255));
  }
}

void JoystickProgram_Run()
{
  if(!digitalRead(KPK_JOY_UP_PIN))
  {
    strip.setPixelColor(gridPin(1, 2), strip.Color(255, 255, 255));
  }

  if(!digitalRead(KPK_JOY_LEFT_PIN))
  {
    strip.setPixelColor(gridPin(2, 1), strip.Color(255, 255, 255));
  }

  if(!digitalRead(KPK_JOY_CLICK_PIN))
  {
    strip.setPixelColor(gridPin(2, 2), strip.Color(255, 255, 255));
  }

  if(!digitalRead(KPK_JOY_RIGHT_PIN))
  {
    strip.setPixelColor(gridPin(2, 3), strip.Color(255, 255, 255));
  }

  if(!digitalRead(KPK_JOY_DOWN_PIN))
  {
    strip.setPixelColor(gridPin(3, 2), strip.Color(255, 255, 255));
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(64); // 1/4 brightness
  strip.clear();
  strip.show();

  pinMode(KPK_JOY_UP_PIN, INPUT_PULLUP);
  pinMode(KPK_JOY_LEFT_PIN, INPUT_PULLUP);
  pinMode(KPK_JOY_RIGHT_PIN, INPUT_PULLUP);
  pinMode(KPK_JOY_DOWN_PIN, INPUT_PULLUP);

  // ledcSetup(1, 2000, 8);
  // ledcAttachPin(22, 1);
}

void loop() {
  strip.clear();

  // DisplayProgram_Run();
  KnobProgram_Run();
  ButtonProgram_Run();
  JoystickProgram_Run();

  NeoPixels_Show();
  delay(5);

  // ledcWriteTone(0, 440);
  // ledcWrite(1, 127);
  // delay(200);
}
