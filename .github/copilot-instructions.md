# EMDR LED Device - ESP32 Project

## Project Overview
ESP32-based EMDR therapeutic device controlling WS2812B addressable LED strip with bouncing snake animation.

## Hardware Configuration
- **Board**: ESP32 (esp-wrover-kit)
- **LED Strip**: WS2812B (COLOR_ORDER: GRB)
- **LED Data Pin**: GPIO 13
- **Speed Control**: Potentiometer on GPIO 34 (ADC1_CH6)
- **Brightness Control**: Potentiometer on GPIO 35 (ADC1_CH7)
- **Color Switch Button**: GPIO 32 (pull-up configuration)
- **Default LED Count**: 104
- **Snake Length**: 5 LEDs

## Core Logic
1. **Snake Movement**: Single direction movement (+1 or -1 position per update)
2. **Bounce Behavior**: Direction reverses when snake head reaches position 0 or NUM_LEDS-1
3. **Visual Effect**: Selectable colors with gradient tail (each segment progressively dimmer)
4. **Non-blocking Updates**: millis()-based timing, no delay() usage
5. **Button Control**: Short press cycles colors, long press (2s) returns to default

## Control Parameters
- **Speed Range**: 5-80ms delay between updates (inverse mapping from ADC)
- **Brightness Range**: 10-255 (direct mapping from ADC)
- **ADC Resolution**: 12-bit (0-4095)
- **Available Colors**: 7 EMDR-friendly colors in HSV format
  - Warm White (default): HSV(30, 180)
  - Red: HSV(0, 255)
  - Green: HSV(96, 255)
  - Blue: HSV(160, 255)
  - Yellow: HSV(64, 255)
  - Cyan: HSV(192, 255)
  - Magenta: HSV(224, 255)
- **Long Press Duration**: 2000ms

## Dependencies
- FastLED library (^3.6.0)
- OneButton library (^2.0.3)
- Arduino framework

## Code Standards
- Minimal comments, English only
- Use FastLED HSV color space for smooth color transitions
- All timing must be non-blocking (millis() based)
- ADC reads should use analogRead() on ADC1 pins only
- Button handling via OneButton library (attachClick, attachLongPressStart)

## Key Functions
- `FastLED.clear()` - Clear all LEDs before each frame
- `FastLED.show()` - Update LED strip after drawing
- `FastLED.setBrightness()` - Global brightness control
- `CHSV(hue, sat, val)` - HSV color assignment
- `button.tick()` - Process button events (call in loop)
- `button.attachClick()` - Register short press handler
- `button.attachLongPressStart()` - Register long press handler

## Pin Restrictions
- Use only ADC1 pins (32-39) for analog input when WiFi enabled
- Avoid ADC2 pins (0, 2, 4, 12-15, 25-27) for potentiometers
