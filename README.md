# EMDR LED Controller

ESP32-based therapeutic device that creates a bouncing light animation on a WS2812B LED strip for EMDR (Eye Movement Desensitization and Reprocessing) therapy.

## Features

- **Smooth bouncing animation**: 5-LED "snake" that moves back and forth across the strip
- **Real-time speed control**: Adjustable via potentiometer (10-200ms intervals)
- **Brightness control**: Variable brightness from dim to full intensity
- **Color cycling**: Smooth HSV color transitions with gradient tail effect

## Hardware Requirements

- ESP32 development board
- WS2812B addressable LED strip (60 LEDs default)
- 2x potentiometers for speed and brightness control
- Connecting wires

## Pin Configuration

| Component | Pin | Description |
|-----------|-----|-------------|
| LED Strip | GPIO 13 | Data line |
| Speed Control | GPIO 34 | Potentiometer (ADC1_CH6) |
| Brightness Control | GPIO 35 | Potentiometer (ADC1_CH7) |

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