# Pico WS2812 Library

A lightweight C library for the Raspberry Pi Pico to control WS2812 LEDs.

## 📚 Functions
- **ws2812_init**: Initializes a WS2812 LED struct.
- **ws2812_write**: Writes a color value to a WS2812 LED.
- **ws2812_program_init**: Initializes a PIO state machine to send WS2812 rgb signals.
- **rgb_to_grb**: Converts RGB values to GRB format.

## 🛠️ Setup
### 1. Add Repository as a Submodule
```bash
git submodule add https://github.com/Danielaca18/pico-ws2812-lib.git
```
### 2. Include the Library
Include the library in your project by adding the following line to your project cmake:
```cmake
add_subdirectory(pico-ws2812-lib)
target_link_libraries(your_project pico-ws2812-lib)
```

## 💼 License
This project is licensed under the [MIT License](LICENSE), which is a permissive open-source license that allows you to use, modify, and distribute the code for both commercial and non-commercial purposes. You can find the full text of the license in the [LICENSE](LICENSE) file.
