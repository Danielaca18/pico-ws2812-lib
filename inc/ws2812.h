/**
 * @file ws2812.h
 * @author Daniel Castro (dcastro@ualberta.ca)
 * @brief Header file for WS2812 LED control.
 * @version 0.1
 * @date 2024-08-02
 * 
 * This file contains the function prototypes and type definitions
 * for controlling WS2812 LEDs using the PIO capabilities of the
 * Raspberry Pi Pico.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef WS2812_H
#define WS2812_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "bootsel.h"
#include "ws2812.pio.h"


#define RGB             24
#define WS2812_PIN      23
#define WS2812_FREQ     800000

/**
 * @brief Struct representing WS2812 LED.
 * 
 */
typedef struct {
    PIO pio;    /**< Struct representing specific PIO module. */
    uint sm;    /**< Index of state machine. */
} ws2812;

/**
 * @brief Initializes a PIO state machine to send ws2812 rgb signals.
 * 
 * @param pio The PIO struct to initialize.
 * @param sm The index of the state machine to initialize.
 * @param offset The memory offset to the program instructions.
 * @param pin The GPIO pin connected to the LED.
 * @param freq The frequency of the WS2812 LED.
 * @param rgb_bits The number of bits per color. (24 for RGB, 32 for RGBW)
 */
void ws2812_program_init(PIO pio, uint sm, uint offset, uint pin, uint freq, uint rgb_bits);

/**
 * @brief Initializes the WS2812 LED
 * 
 * @param pin The GPIO pin connected to the LED.
 * @param freq The frequency of the WS2812 LED.
 * @param rgb_bits The number of bits per color. (24 for RGB, 32 for RGBW)
 * @return An initialized ws2812 struct.
 */
ws2812 ws2812_init(uint pin, uint freq, uint rgb_bits);

/**
 * @brief Writes a color value to a WS2812 LED.
 * 
 * @param led The ws2812 LED struct.
 * @param r The red component of the color (0-255).
 * @param g The green component of the color (0-255).
 * @param b The blue component of the color (0-255).
 */
void ws2812_write(ws2812 led, uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Converts RGB values to GRB format.
 * 
 * @param r The red component of the color (0-255).
 * @param g The green component of the color (0-255).
 * @param b The blue component of the color (0-255).
 * @return uint32_t 
 */
inline uint32_t rgb_to_grb(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(g) << 16u | (uint32_t)(r) << 8u | (uint32_t)(b)) << 8u;
}

#endif