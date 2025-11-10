#include <FastLED.h>

#define LED_PIN 13
#define NUM_LEDS 104
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

#define SPEED_POT_PIN 34
#define BRIGHTNESS_POT_PIN 35

#define SNAKE_LENGTH 5
#define MIN_DELAY 5
#define MAX_DELAY 80

CRGB leds[NUM_LEDS];

int snakePos = 0;
int direction = 1;
unsigned long lastUpdate = 0;
int delayTime = 50;
uint8_t brightness = 128;

void setup() {
    Serial.begin(115200);
    
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS)
        .setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(brightness);
    FastLED.clear();
}

void loop() {
    unsigned long currentMillis = millis();
    
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
        for (int i = 0; i < SNAKE_LENGTH; i++) {
            int pos = snakePos - (i * direction);
            
            if (pos >= 0 && pos < NUM_LEDS) {
                uint8_t brightness = 255 - (i * (255 / SNAKE_LENGTH));
                leds[pos] = CHSV(30, 180, brightness);
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
