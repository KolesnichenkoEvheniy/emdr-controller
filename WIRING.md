# Hardware Wiring Guide

## Complete Pin Assignment

| Component | ESP32 Pin | Connection Details |
|-----------|-----------|-------------------|
| LED Strip Data | GPIO 13 | WS2812B data line |
| Speed Potentiometer | GPIO 34 | ADC1_CH6 (see potentiometer wiring below) |
| Brightness Potentiometer | GPIO 35 | ADC1_CH7 (see potentiometer wiring below) |
| Color Button | GPIO 32 | Pull-up mode: one side to GPIO 32, other to GND |

## Potentiometer Connections

Each potentiometer has 3 pins:
- **Pin 1**: Connect to **GND**
- **Pin 2** (middle/wiper): Connect to respective GPIO (34 for speed, 35 for brightness)
- **Pin 3**: Connect to **3.3V**

## Button Connection (Pull-up Configuration)

**Wiring Steps:**
1. Connect one side of the button to **GPIO 32**
2. Connect the other side to **GND**
3. Internal pull-up resistor enabled in software (no external resistor needed)

**Button Functions:**
- **Short press** (< 2 seconds): Cycle through colors
  - Warm White → Red → Green → Blue → Yellow → Cyan → Magenta → (loops back)
- **Long press** (≥ 2 seconds): Return to default warm white color

## Power Supply

- **ESP32**: USB or external 5V power supply
- **LED Strip**: External 5V power supply (capacity depends on LED count - recommend 60mA per LED at full brightness)
- **Important**: Connect common GND between ESP32 and LED strip power supply

## Available Colors (HSV Format)

1. Warm White (default) - HSV(30, 180)
2. Red - HSV(0, 255)
3. Green - HSV(96, 255)
4. Blue - HSV(160, 255)
5. Yellow - HSV(64, 255)
6. Cyan - HSV(192, 255)
7. Magenta - HSV(224, 255)
