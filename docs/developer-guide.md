# Developer Guide

## Table of Contents
- [Project Structure](#project-structure)
- [Core Components](#core-components)
- [Pattern Development](#pattern-development)
- [Testing](#testing)
- [Contributing](#contributing)
- [Best Practices](#best-practices)

## Project Structure

```
NeoPixelFun/
├── src/
│   ├── main.cpp                 # Main program entry
│   ├── config.h                 # Configuration settings
│   ├── NeoPixelController.h     # LED control interface
│   ├── NeoPixelController.cpp   # LED control implementation
│   ├── PatternGenerator.h       # Pattern generation interface
│   └── PatternGenerator.cpp     # Pattern implementations
├── docs/
│   ├── setup-and-usage.md      # User guide
│   └── developer-guide.md      # This document
├── platformio.ini              # Project configuration
└── README.md                   # Project overview
```

## Core Components

### 1. NeoPixelController Class

The `NeoPixelController` class manages the LED hardware interface:

```cpp
class NeoPixelController {
public:
    void setPixel(uint16_t index, CRGBW color);
    void setPixel(uint8_t panel, uint8_t x, uint8_t y, CRGBW color);
    // ... other methods
};
```

Key responsibilities:
- Direct LED control
- Pixel addressing
- Brightness management
- Color handling

### 2. PatternGenerator Class

The `PatternGenerator` class manages pattern creation and animation:

```cpp
class PatternGenerator {
public:
    void update();
    void setPattern(PatternType pattern);
    // ... other methods
};
```

Key responsibilities:
- Pattern implementation
- Animation timing
- State management
- Color transitions

## Pattern Development

### Creating New Patterns

1. **Add Pattern Type**
   ```cpp
   // In config.h
   enum PatternType {
       PATTERN_LIGHTS_OUT,
       PATTERN_BIOSQUARE,
       PATTERN_FRACTAL,
       YOUR_NEW_PATTERN  // Add new pattern type
   };
   ```

2. **Implement Pattern Logic**
   ```cpp
   // In PatternGenerator.h
   void updateYourPattern();  // Declare new method

   // In PatternGenerator.cpp
   void PatternGenerator::updateYourPattern() {
       // Implement pattern logic
   }
   ```

3. **Update Pattern Selection**
   ```cpp
   // In PatternGenerator.cpp
   void PatternGenerator::update() {
       switch (currentPattern) {
           // ... existing cases
           case YOUR_NEW_PATTERN:
               updateYourPattern();
               break;
       }
   }
   ```

### Pattern Guidelines

1. **Performance**
   - Maintain 50 pixel maximum
   - Optimize calculations
   - Use efficient memory management

2. **Animation**
   - Smooth transitions
   - Consistent timing
   - Proper state management

3. **Color Management**
   - Use defined color palettes
   - Implement proper fading
   - Consider color theory

## Testing

### Unit Testing

1. **Test Pattern Logic**
   ```cpp
   void testYourPattern() {
       // Setup
       PatternGenerator pattern(controller);
       pattern.setPattern(YOUR_NEW_PATTERN);
       
       // Test cases
       pattern.update();
       // Verify expected states
   }
   ```

2. **Test Pixel Limits**
   ```cpp
   void testPixelLimits() {
       // Verify active pixel count
       // Test boundary conditions
   }
   ```

### Integration Testing

1. **Hardware Testing**
   - Verify timing
   - Check power consumption
   - Test pattern transitions

2. **System Testing**
   - Full pattern sequence
   - Long-running stability
   - Error handling

## Contributing

### Code Style

1. **Naming Conventions**
   - Classes: PascalCase
   - Methods: camelCase
   - Constants: UPPER_CASE
   - Variables: camelCase

2. **Documentation**
   - Comment complex algorithms
   - Document public interfaces
   - Update README for new features

### Pull Request Process

1. **Branch Naming**
   - feature/feature-name
   - fix/bug-description
   - docs/documentation-update

2. **Commit Messages**
   - feat: New feature
   - fix: Bug fix
   - docs: Documentation
   - refactor: Code improvement

3. **Review Process**
   - Code review required
   - Tests must pass
   - Documentation updated

## Best Practices

### Memory Management

1. **Static Allocation**
   - Pre-allocate buffers
   - Avoid dynamic allocation
   - Use const where possible

2. **Resource Usage**
   - Monitor stack usage
   - Optimize loop calculations
   - Minimize blocking operations

### Performance Optimization

1. **Timing**
   - Use non-blocking delays
   - Optimize critical paths
   - Profile pattern performance

2. **Power Efficiency**
   - Implement power-saving features
   - Monitor current draw
   - Optimize brightness levels

### Error Handling

1. **Validation**
   - Check input parameters
   - Validate pixel indices
   - Handle edge cases

2. **Recovery**
   - Implement fallback modes
   - Log error conditions
   - Provide debug information 