#ifndef KPK_DEFINES_H
#define KPK_DEFINES_H

// Most of these sourced from here: https://github.com/murilopolese/kano-pixel-kit-pixel32/blob/master/python/PixelKit.py

// All buttons (including joystick) are inverted. That is, digitalRead returns true when idle and false when active

#define KPK_NEO_PIN        4     // Pin to which the neopixel strand is attached
#define KPK_NEO_CNT        128   // Total number of neopixels in the strand
#define KPK_NEO_COLS       16    // Number of columns into which the neopixels are arranged
#define KPK_NEO_ROWS       8     // Number of rows into which the neopixels are arranged
#define KPK_POT_PIN        36    // Pin to which the potentiometer (knob) is connected
#define KPK_JOY_UP_PIN     35    // Joystick up pin (Requires internal pull-up)
#define KPK_JOY_DOWN_PIN   34    // Joystick down pin (Requires internal pull-up)
#define KPK_JOY_LEFT_PIN   26    // Joystick left pin (Requires internal pull-up)
#define KPK_JOY_RIGHT_PIN  25    // Joystick right pin (Requires internal pull-up)
#define KPK_JOY_CLICK_PIN  27    // Joystick center pin
#define KPK_BTN_B_PIN      18    // Button B pin
#define KPK_BTN_A_PIN      23    // Button A pin
#define KPK_BTN_NONE_PIN   5     // Small button on the back of the board labelled BM1

#endif // KPK_DEFINES_H
