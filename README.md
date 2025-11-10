# EMDR LED Controller

ESP32-based therapeutic device that creates a bouncing light animation on a WS2812B LED strip for EMDR (Eye Movement Desensitization and Reprocessing) therapy.

## Features

- **Smooth bouncing animation**: 5-LED "snake" that moves back and forth across the strip
- **Real-time speed control**: Adjustable via potentiometer (5-80ms intervals)
- **Brightness control**: Variable brightness from dim to full intensity
- **Color selection**: 7 EMDR-friendly colors switchable via button
- **Warm LED default**: Therapeutic warm white color optimized for EMDR therapy

## Hardware Requirements

- ESP32 development board (esp-wrover-kit)
- WS2812B addressable LED strip (104 LEDs default)
- 2x potentiometers for speed and brightness control
- 1x push button for color selection
- Connecting wires

## Pin Configuration

| Component | Pin | Description |
|-----------|-----|-------------|
| LED Strip | GPIO 13 | Data line |
| Speed Control | GPIO 34 | Potentiometer (ADC1_CH6) |
| Brightness Control | GPIO 35 | Potentiometer (ADC1_CH7) |
| Color Button | GPIO 32 | Push button (pull-up, connect to GND) |

## Quick Start

1. **Install PlatformIO** in VS Code
2. **Clone** this repository
3. **Connect** your ESP32 and LED strip according to pin configuration
4. **Upload** the firmware:
   ```bash
   platformio run --target upload
   ```

## Dependencies

- [FastLED](https://github.com/FastLED/FastLED) ^3.6.0 (automatically installed)

## Usage

- Turn the **speed potentiometer** to adjust animation speed
- Turn the **brightness potentiometer** to adjust LED intensity
- The LED snake will continuously bounce between the strip endpoints

## Configuration

Modify `main.cpp` to customize:
- `NUM_LEDS`: Number of LEDs in your strip (default: 60)
- `SNAKE_LENGTH`: Length of the moving animation (default: 5)
- Speed and brightness ranges in the mapping functions