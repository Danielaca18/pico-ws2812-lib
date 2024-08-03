/**
 * @file ws2812.c
 * @author Daniel Castro (dcastro@ualberta.ca)
 * @brief Source file for WS2812 LED control.
 * @version 0.1
 * @date 2024-08-02
 * 
 * This file contains the function definitions
 * for controlling WS2812 LEDs using the PIO capabilities of the
 * Raspberry Pi Pico.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ws2812.h"

void ws2812_program_init(PIO pio, uint sm, uint offset, uint pin, uint freq, uint rgb_bits) {
    pio_sm_config config = ws2812_program_get_default_config(offset);

    // configure sideset pins
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
    sm_config_set_sideset_pins(&config, pin);

    // configure osr to auto pull from fifo
    sm_config_set_out_shift(&config, false, true, rgb_bits);

    // extend fifo to hold up to 8 rgb values
    sm_config_set_fifo_join(&config, PIO_FIFO_JOIN_TX);

    // set state machine frequency
    int target_freq = (ws2812_T1 * 3) * freq;
    //int target_freq = (ws2812_T1 + ws2812_T2 + ws2812_T3) * freq;
    float div = clock_get_hz(clk_sys) / target_freq;
    sm_config_set_clkdiv(&config, div);
    
    // init and enable state machine
    pio_sm_init(pio, sm, offset, &config);
    pio_sm_set_enabled(pio, sm, true);
}

ws2812 ws2812_init(uint pin, uint freq, uint rgb_bits) {
    uint offset = pio_add_program(pio0, &ws2812_program);
    uint sm = pio_claim_unused_sm(pio0, true);
    ws2812_program_init(pio0, sm, offset, pin, freq, rgb_bits);
    ws2812 led = {pio0, sm};
    return led;
}

void ws2812_write(ws2812 led, uint8_t r, uint8_t g, uint8_t b) {
    uint32_t grb = rgb_to_grb(r, g, b);
    pio_sm_put_blocking(led.pio, led.sm, grb);
}