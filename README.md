# NeoPixelFun

A creative lighting project for ESP32 controlling a 3x3 grid of NeoPixel panels (900 total pixels) with various fractal and pattern effects.

## Hardware Requirements

- ESP32 Development Board
- 9x NeoPixel Grid Panels (10x10 each)
- 5V Power Supply (adequate for NeoPixels)
- Connecting wires

## Panel Configuration

- Grid Layout: 3x3 panels
- Panels per grid: 9
- Pixels per panel: 100 (10x10)
- Total pixels: 900
- Maximum simultaneous illuminated pixels: 50

## Features

- Configurable lighting patterns
- RGBW color support
- Layered color effects
- "Lights Out" / "BioSquare" style patterns
- Fractal-based animations

## Setup

1. Connect the NeoPixel panels to the ESP32:
   - Data pin: GPIO 5 (configurable)
   - Power: 5V
   - Ground: GND

2. Install required libraries:
   - FastLED
   - ArduinoJson (for configuration)

3. Configure your patterns in `config.h`

## Building and Uploading

1. Open the project in PlatformIO or Arduino IDE
2. Select your ESP32 board
3. Build and upload

## Configuration

Edit `config.h` to customize:
- Pin assignments
- Pattern parameters
- Color schemes
- Animation speeds

## License

MIT License - See LICENSE file for details
