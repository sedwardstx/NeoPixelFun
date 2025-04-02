# Setup and Usage Guide

## Table of Contents
- [Hardware Requirements](#hardware-requirements)
- [Hardware Setup](#hardware-setup)
- [Software Installation](#software-installation)
- [Configuration](#configuration)
- [Running the Project](#running-the-project)
- [Pattern Controls](#pattern-controls)
- [Troubleshooting](#troubleshooting)

## Hardware Requirements

### Components
- ESP32 Development Board
- 9x NeoPixel Grid Panels (10x10 each)
- 5V Power Supply (rated for NeoPixels)
- Data Level Shifter (3.3V to 5V) - recommended
- Connecting wires
- USB Cable for programming

### Power Calculations
- Each RGBW NeoPixel can draw up to 60mA at full brightness
- Maximum theoretical power draw: 900 pixels × 60mA = 54A
- Actual maximum draw (50 active pixels): 50 × 60mA = 3A
- Recommended power supply: 5V, 5A (includes safety margin)

## Hardware Setup

1. **Power Distribution**
   - Connect 5V power supply to power distribution points
   - Ensure proper power injection for each panel
   - Connect ground to all panels and ESP32

2. **Data Connection**
   - Connect ESP32 GPIO 5 to data level shifter input (if used)
   - Connect level shifter output to first panel's data input
   - Chain data connections between panels in sequence

3. **Panel Layout**
   ```
   [P1][P2][P3]
   [P4][P5][P6]
   [P7][P8][P9]
   ```
   - Ensure correct data flow direction between panels
   - Verify ground connections between all components

## Software Installation

1. **Development Environment**
   - Install Visual Studio Code
   - Install PlatformIO IDE extension
   - Clone the repository:
     ```bash
     git clone https://github.com/sedwardstx/NeoPixelFun.git
     cd NeoPixelFun
     ```

2. **Dependencies**
   - PlatformIO will automatically install:
     - FastLED library
     - ArduinoJson library

## Configuration

1. **Hardware Configuration**
   Edit `config.h` to match your setup:
   ```cpp
   #define DATA_PIN 5          // GPIO pin number
   #define NUM_PANELS 9        // Number of panels
   #define PANEL_SIZE 100      // Pixels per panel
   ```

2. **Pattern Configuration**
   - Adjust brightness: `DEFAULT_BRIGHTNESS` (0-255)
   - Modify animation speed: `DEFAULT_SPEED`
   - Configure color palettes in `baseColors[]`

## Running the Project

1. **Building and Uploading**
   - Open project in VS Code with PlatformIO
   - Connect ESP32 via USB
   - Click "Upload" in PlatformIO
   - Monitor serial output at 115200 baud

2. **Initial Testing**
   - Verify power connections before full power-up
   - Start with reduced brightness
   - Test each panel individually

## Pattern Controls

Control patterns via Serial Monitor (115200 baud):

| Command | Action |
|---------|--------|
| 1 | Lights Out pattern |
| 2 | BioSquare pattern |
| 3 | Fractal pattern |
| r | Reset current pattern |
| h | Display help menu |

## Troubleshooting

### Common Issues

1. **No Lights**
   - Check power connections
   - Verify data pin configuration
   - Ensure proper ground connections

2. **Erratic Behavior**
   - Check data signal integrity
   - Verify power supply capacity
   - Ensure proper grounding

3. **Wrong Colors**
   - Check `COLOR_ORDER` setting
   - Verify panel type configuration
   - Check data signal timing

### Debug Tips
- Monitor serial output for errors
- Use `CORE_DEBUG_LEVEL` for detailed logging
- Test with minimal pixels first
- Verify voltage levels at panels 