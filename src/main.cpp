#include <Arduino.h>
#include "NeoPixelController.h"
#include "PatternGenerator.h"

NeoPixelController neoPixels;
PatternGenerator patternGen(neoPixels);

void setup() {
    Serial.begin(115200);
    Serial.println("NeoPixelFun Starting...");
    
    neoPixels.begin();
    patternGen.setPattern(PATTERN_LIGHTS_OUT);
}

void loop() {
    patternGen.update();
    delay(DEFAULT_SPEED);
    
    // Check for serial commands
    if (Serial.available()) {
        char cmd = Serial.read();
        switch (cmd) {
            case '1':
                patternGen.setPattern(PATTERN_LIGHTS_OUT);
                break;
            case '2':
                patternGen.setPattern(PATTERN_BIOSQUARE);
                break;
            case '3':
                patternGen.setPattern(PATTERN_FRACTAL);
                break;
            case 'r':
                patternGen.reset();
                break;
            case 'h':
                Serial.println("Commands:");
                Serial.println("1 - Lights Out pattern");
                Serial.println("2 - BioSquare pattern");
                Serial.println("3 - Fractal pattern");
                Serial.println("r - Reset current pattern");
                Serial.println("h - Show this help");
                break;
        }
    }
} 