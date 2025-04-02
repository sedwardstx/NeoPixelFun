#ifndef CONFIG_H
#define CONFIG_H

#include <FastLED.h>

// Hardware Configuration
#define NUM_PANELS 9
#define PANEL_SIZE 100  // 10x10
#define TOTAL_PIXELS (NUM_PANELS * PANEL_SIZE)
#define MAX_ACTIVE_PIXELS 50
#define DATA_PIN 5

// Pattern Configuration
#define DEFAULT_BRIGHTNESS 64
#define DEFAULT_SPEED 50  // milliseconds between updates

// Color Definitions
#define COLOR_ORDER GRBW
#define COLOR_DEPTH 8

// Pattern Types
enum PatternType {
    PATTERN_LIGHTS_OUT,
    PATTERN_BIOSQUARE,
    PATTERN_FRACTAL
};

// Animation States
struct AnimationState {
    uint8_t currentLevel;
    uint8_t maxLevel;
    uint16_t frameCount;
    bool isAscending;
};

// Color Palette Configuration
const CRGBW baseColors[] = {
    CRGBW(0, 0, 0, 0),      // Off
    CRGBW(0, 0, 0, 64),     // White Level 1
    CRGBW(0, 0, 0, 128),    // White Level 2
    CRGBW(0, 0, 0, 255),    // White Level 3
    CRGBW(0, 0, 64, 255),   // Blue Level 1
    CRGBW(0, 0, 128, 255),  // Blue Level 2
    CRGBW(0, 0, 255, 255),  // Blue Level 3
    CRGBW(64, 0, 255, 255), // Purple Level 1
    CRGBW(128, 0, 255, 255),// Purple Level 2
    CRGBW(255, 0, 255, 255) // Purple Level 3
};

// Grid Layout Configuration
struct GridLayout {
    static const uint8_t ROWS = 3;
    static const uint8_t COLS = 3;
    static const uint8_t PANEL_ROWS = 10;
    static const uint8_t PANEL_COLS = 10;
};

#endif // CONFIG_H 