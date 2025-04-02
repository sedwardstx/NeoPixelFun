#ifndef PATTERN_GENERATOR_H
#define PATTERN_GENERATOR_H

#include "NeoPixelController.h"
#include "config.h"

class PatternGenerator {
public:
    PatternGenerator(NeoPixelController& controller);
    void update();
    void setPattern(PatternType pattern);
    void reset();
    
private:
    NeoPixelController& controller;
    PatternType currentPattern;
    AnimationState state;
    
    // Pattern-specific methods
    void updateLightsOut();
    void updateBioSquare();
    void updateFractal();
    
    // Helper methods
    void initializeLevel(uint8_t level);
    void clearLevel(uint8_t level);
    uint8_t getActivePixelsForLevel(uint8_t level) const;
    CRGBW getColorForLevel(uint8_t level) const;
    bool shouldTransition() const;
    void transitionLevel();
};

#endif // PATTERN_GENERATOR_H 