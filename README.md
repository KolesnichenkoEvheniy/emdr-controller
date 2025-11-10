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
- [OneButton](https://github.com/mathertel/OneButton) ^2.0.3 (automatically installed)

## Usage

- **Speed potentiometer**: Adjust animation speed (faster/slower)
- **Brightness potentiometer**: Control LED intensity
- **Color button**:
  - **Short press**: Cycle through 7 colors (Warm White → Red → Green → Blue → Yellow → Cyan → Magenta)
  - **Long press** (2 seconds): Return to default warm white color
- The LED snake continuously bounces between the strip endpoints

## Available Colors

1. Warm White (default) - Therapeutic warm tone
2. Red
3. Green
4. Blue
5. Yellow
6. Cyan
7. Magenta

## Configuration

Modify `src/main.cpp` to customize:
- `NUM_LEDS`: Number of LEDs in your strip (default: 104)
- `SNAKE_LENGTH`: Length of the moving animation (default: 5)
- Speed range: `MIN_DELAY` (5ms) to `MAX_DELAY` (80ms)
- Color array in `COLORS[]` for custom color palette

For detailed wiring instructions, see [WIRING.md](WIRING.md)