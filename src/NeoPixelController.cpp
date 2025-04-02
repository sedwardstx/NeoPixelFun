#include "NeoPixelController.h"

NeoPixelController::NeoPixelController() : currentBrightness(DEFAULT_BRIGHTNESS) {
    FastLED.addLeds<NEOPIXEL, DATA_PIN, COLOR_ORDER>(leds, TOTAL_PIXELS);
}

void NeoPixelController::begin() {
    FastLED.setBrightness(currentBrightness);
    clear();
    show();
}

void NeoPixelController::clear() {
    fill(CRGBW(0, 0, 0, 0));
}

void NeoPixelController::show() {
    FastLED.show();
}

void NeoPixelController::setPixel(uint16_t index, CRGBW color) {
    if (isValidPixel(index)) {
        leds[index] = color;
    }
}

void NeoPixelController::setPixel(uint8_t panel, uint8_t x, uint8_t y, CRGBW color) {
    uint16_t index = getPixelIndex(panel, x, y);
    setPixel(index, color);
}

void NeoPixelController::setBrightness(uint8_t brightness) {
    currentBrightness = brightness;
    FastLED.setBrightness(brightness);
}

void NeoPixelController::fill(CRGBW color) {
    for (uint16_t i = 0; i < TOTAL_PIXELS; i++) {
        leds[i] = color;
    }
}

void NeoPixelController::fadeToBlack(uint8_t amount) {
    for (uint16_t i = 0; i < TOTAL_PIXELS; i++) {
        leds[i].fadeToBlack(amount);
    }
}

uint16_t NeoPixelController::getPixelIndex(uint8_t panel, uint8_t x, uint8_t y) const {
    if (panel >= NUM_PANELS || x >= GridLayout::PANEL_COLS || y >= GridLayout::PANEL_ROWS) {
        return TOTAL_PIXELS; // Invalid index
    }
    
    // Calculate panel offset
    uint16_t panelOffset = panel * PANEL_SIZE;
    
    // Calculate position within panel
    uint16_t position = (y * GridLayout::PANEL_COLS) + x;
    
    return panelOffset + position;
}

bool NeoPixelController::isValidPixel(uint16_t index) const {
    return index < TOTAL_PIXELS;
} 