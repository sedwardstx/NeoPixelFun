#ifndef NEOPIXEL_CONTROLLER_H
#define NEOPIXEL_CONTROLLER_H

#include <FastLED.h>
#include "config.h"

class NeoPixelController {
public:
    NeoPixelController();
    void begin();
    void clear();
    void show();
    void setPixel(uint16_t index, CRGBW color);
    void setPixel(uint8_t panel, uint8_t x, uint8_t y, CRGBW color);
    void setBrightness(uint8_t brightness);
    uint16_t getTotalPixels() const { return TOTAL_PIXELS; }
    void fill(CRGBW color);
    void fadeToBlack(uint8_t amount);
    
private:
    CRGBW leds[TOTAL_PIXELS];
    uint8_t currentBrightness;
    
    uint16_t getPixelIndex(uint8_t panel, uint8_t x, uint8_t y) const;
    bool isValidPixel(uint16_t index) const;
};

#endif // NEOPIXEL_CONTROLLER_H 