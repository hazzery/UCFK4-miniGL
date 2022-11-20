//
// Created by Harry on 25/10/22.
//

#include "../../utils/pacer.h"
#include "../../drivers/led.h"
#include "../miniGL.h"

#define PIXEL_MAX 127

int main(void)
{
    pacer_init(50000);
//    miniGL_init();
    led_init();

//    miniGL_set_pixel((miniGL_pos_t){.col = 0, .row = 0}, PIXEL_MAX);
//    miniGL_set_pixel((miniGL_pos_t){.col = 1, .row = 0}, PIXEL_MAX);
//    miniGL_set_pixel((miniGL_pos_t){.col = 2, .row = 0}, PIXEL_MAX);
//    miniGL_set_pixel((miniGL_pos_t){.col = 3, .row = 0}, PIXEL_MAX);
//    miniGL_set_pixel((miniGL_pos_t){.col = 4, .row = 0}, PIXEL_MAX);
    int8_t count = 0;
    while (1) {
        led_set(0, count <= 42);
        count++;
        pacer_wait();
    }
}
//        miniGL_update();
