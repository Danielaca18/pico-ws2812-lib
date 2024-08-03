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