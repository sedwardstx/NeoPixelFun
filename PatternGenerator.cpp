#include "PatternGenerator.h"
#include <random>

PatternGenerator::PatternGenerator(NeoPixelController& controller) 
    : controller(controller), currentPattern(PATTERN_LIGHTS_OUT) {
    reset();
}

void PatternGenerator::update() {
    switch (currentPattern) {
        case PATTERN_LIGHTS_OUT:
            updateLightsOut();
            break;
        case PATTERN_BIOSQUARE:
            updateBioSquare();
            break;
        case PATTERN_FRACTAL:
            updateFractal();
            break;
    }
}

void PatternGenerator::setPattern(PatternType pattern) {
    currentPattern = pattern;
    reset();
}

void PatternGenerator::reset() {
    state.currentLevel = 0;
    state.maxLevel = 9; // Based on our color palette
    state.frameCount = 0;
    state.isAscending = true;
    controller.clear();
    initializeLevel(0);
}

void PatternGenerator::updateLightsOut() {
    if (shouldTransition()) {
        transitionLevel();
    }
    
    // Fade existing pixels
    controller.fadeToBlack(32);
    controller.show();
}

void PatternGenerator::updateBioSquare() {
    if (shouldTransition()) {
        transitionLevel();
    }
    
    // Add some organic movement
    static uint8_t offset = 0;
    offset = (offset + 1) % 20;
    
    // Fade existing pixels with varying intensity
    controller.fadeToBlack(16 + (offset % 16));
    controller.show();
}

void PatternGenerator::updateFractal() {
    // To be implemented
    updateLightsOut(); // Fallback for now
}

void PatternGenerator::initializeLevel(uint8_t level) {
    uint8_t activePixels = getActivePixelsForLevel(level);
    CRGBW color = getColorForLevel(level);
    
    // Clear previous level
    clearLevel(level - 1);
    
    // Initialize new pixels
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> panelDist(0, NUM_PANELS - 1);
    std::uniform_int_distribution<> coordDist(0, GridLayout::PANEL_ROWS - 1);
    
    for (uint8_t i = 0; i < activePixels; i++) {
        uint8_t panel = panelDist(gen);
        uint8_t x = coordDist(gen);
        uint8_t y = coordDist(gen);
        controller.setPixel(panel, x, y, color);
    }
}

void PatternGenerator::clearLevel(uint8_t level) {
    if (level >= state.maxLevel) return;
    
    CRGBW color = getColorForLevel(level);
    for (uint16_t i = 0; i < controller.getTotalPixels(); i++) {
        if (controller.getPixel(i) == color) {
            controller.setPixel(i, CRGBW(0, 0, 0, 0));
        }
    }
}

uint8_t PatternGenerator::getActivePixelsForLevel(uint8_t level) const {
    // Exponential growth of active pixels per level
    return (MAX_ACTIVE_PIXELS * level) / state.maxLevel;
}

CRGBW PatternGenerator::getColorForLevel(uint8_t level) const {
    if (level >= sizeof(baseColors) / sizeof(baseColors[0])) {
        return CRGBW(0, 0, 0, 0);
    }
    return baseColors[level];
}

bool PatternGenerator::shouldTransition() const {
    return state.frameCount++ >= DEFAULT_SPEED;
}

void PatternGenerator::transitionLevel() {
    state.frameCount = 0;
    
    if (state.isAscending) {
        if (state.currentLevel < state.maxLevel - 1) {
            state.currentLevel++;
        } else {
            state.isAscending = false;
        }
    } else {
        if (state.currentLevel > 0) {
            state.currentLevel--;
        } else {
            state.isAscending = true;
        }
    }
    
    initializeLevel(state.currentLevel);
} 