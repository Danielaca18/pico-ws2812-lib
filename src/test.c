/**
 * @file test.c
 * @author Daniel Castro (dcastro@ualberta.ca)
 * @brief Test file for WS2812 LED control.
 * @version 0.1
 * @date 2024-08-02
 * 
 * This file contains a main function that runs various tests on the
 * WS2812 LED control functions.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ws2812.h"

int main() {
    ws2812 led = ws2812_init(WS2812_PIN, WS2812_FREQ, RGB);
    
    static uint8_t value = 0;
    while (true) {
        if (get_bootsel_button()) {
            ++value;
            value = value % 4;
            switch (value) {
                case 1:
                    ws2812_write(led, 1, 0 ,0);
                    break;
                case 2:
                    ws2812_write(led, 0, 1, 0);
                    break;
                case 3:
                    ws2812_write(led, 0, 0, 1);
                    break;
                default:
                    ws2812_write(led, 0, 0, 0);
            }
            while (get_bootsel_button());
        }
    }
}