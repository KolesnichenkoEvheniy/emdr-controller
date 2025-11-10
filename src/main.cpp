#include <FastLED.h>
#include <OneButton.h>

#define LED_PIN 13
#define NUM_LEDS 104
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

#define SPEED_POT_PIN 34
#define BRIGHTNESS_POT_PIN 35
#define BUTTON_PIN 32

#define SNAKE_LENGTH 5
#define MIN_DELAY 5
#define MAX_DELAY 80

CRGB leds[NUM_LEDS];
OneButton button(BUTTON_PIN, true);

struct ColorHSV {
    uint8_t hue;
    uint8_t sat;
};

const ColorHSV COLORS[] = {
    {30, 180},   // Warm white (default)
    {0, 255},    // Red
    {96, 255},   // Green
    {160, 255},  // Blue
    {64, 255},   // Yellow
    {192, 255},  // Cyan
    {224, 255}   // Magenta
};
const int NUM_COLORS = sizeof(COLORS) / sizeof(COLORS[0]);

int snakePos = 0;
int direction = 1;
unsigned long lastUpdate = 0;
int delayTime = 50;
uint8_t brightness = 128;
int currentColorIndex = 0;

void handleClick() {
    currentColorIndex = (currentColorIndex + 1) % NUM_COLORS;
}

void handleLongPress() {
    currentColorIndex = 0;
}

void setup() {
    Serial.begin(115200);
    
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS)
        .setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(brightness);
    FastLED.clear();
    
    button.attachClick(handleClick);
    button.attachLongPressStart(handleLongPress);
    button.setLongPressIntervalMs(2000);
}

void loop() {
    unsigned long currentMillis = millis();
    
    button.tick();
    
    // Read potentiometers
    int speedRaw = analogRead(SPEED_POT_PIN);
    int brightnessRaw = analogRead(BRIGHTNESS_POT_PIN);
    
    // Map speed (inverse: lower value = faster)
    delayTime = map(speedRaw, 0, 4095, MIN_DELAY, MAX_DELAY);
    
    // Map brightness
    brightness = map(brightnessRaw, 0, 4095, 10, 255);
    FastLED.setBrightness(brightness);
    
    // Update snake position
    if (currentMillis - lastUpdate >= delayTime) {
        lastUpdate = currentMillis;
        
        // Clear all LEDs
        FastLED.clear();
        
        // Draw snake
        ColorHSV currentColor = COLORS[currentColorIndex];
        for (int i = 0; i < SNAKE_LENGTH; i++) {
            int pos = snakePos - (i * direction);
            
            if (pos >= 0 && pos < NUM_LEDS) {
                uint8_t brightness = 255 - (i * (255 / SNAKE_LENGTH));
                leds[pos] = CHSV(currentColor.hue, currentColor.sat, brightness);
            }
        }
        
        // Move snake
        snakePos += direction;
        
        // Bounce at edges
        if (snakePos >= NUM_LEDS - 1) {
            snakePos = NUM_LEDS - 1;
            direction = -1;
        } else if (snakePos <= 0) {
            snakePos = 0;
            direction = 1;
        }
        
        FastLED.show();
    }
}
