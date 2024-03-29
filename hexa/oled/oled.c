#include "quantum.h"
#include "oled.h"  
#include "config.h"



void render_home(void) {
    static const char PROGMEM home[] = { //32x32
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x30, 0x30, 0xcc, 0xcc, 0xf3, 
        0xf3, 0xcc, 0xcc, 0x30, 0x30, 0x70, 0xff, 0xff, 0x03, 0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x80, 0x80, 0x60, 0x60, 0x98, 0x9c, 0xe2, 0xe3, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0xe0, 0x9f, 0x9f, 0x60, 0x60, 0x80, 0x80, 
        0x01, 0x01, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 
        0x07, 0x07, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x01, 0x01, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00
    };
    oled_write_raw_P(home, sizeof(home));
    oled_set_cursor(0, 4);
}

void render_code(void) {
    static const char PROGMEM code[] = { //32x32
        0xf0, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0xf0, 
        0xff, 0x00, 0x00, 0x00, 0x00, 0x10, 0x28, 0x08, 0x44, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x44, 0x40, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0x3f, 0x00, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0xd0, 0x50, 0x50, 
        0x50, 0x50, 0xd0, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x00, 0x3f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x04, 0x06, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x06, 0x04, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(code, sizeof(code));
    oled_set_cursor(0, 4);
}

void render_car(void) {
    static const char PROGMEM car [] = { //32x32
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 
        0xc0, 0x60, 0x30, 0x1e, 0x13, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x18, 0x1c, 0x16, 0x13, 0x11, 0x11, 0x11, 0x13, 0x1e, 0x1c, 0x11, 0x1f, 0x18, 0x60, 0xc0, 
        0xff, 0xc0, 0x80, 0x8f, 0x9f, 0x99, 0x99, 0x99, 0x9f, 0x8f, 0x80, 0x80, 0x8a, 0x8a, 0x8a, 0x8a, 
        0x8a, 0x8a, 0x8a, 0x8a, 0x80, 0x80, 0x8f, 0x9f, 0x99, 0x99, 0x99, 0x9f, 0x8f, 0x80, 0xc0, 0xff, 
        0x07, 0x0c, 0x08, 0x08, 0x08, 0x08, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x07
    };

    oled_write_raw_P(car, sizeof(car));
    oled_set_cursor(0, 4);
}

void render_arcade(void) {
    static const char PROGMEM arcade [] = {  //32x32
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xfc, 0xfc, 0xfe, 
        0xfe, 0xfc, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xff, 0x01, 
        0x01, 0xff, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
        0x00, 0x83, 0xc7, 0x8f, 0x8f, 0x1f, 0x1f, 0x3f, 0x7c, 0x78, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xfe, 
        0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0xc7, 0x83, 0x00, 
        0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0e, 0x0e, 0x1c, 0x18, 0x38, 0x38, 0x31, 0x71, 0x71, 
        0x71, 0x71, 0x31, 0x38, 0x38, 0x18, 0x1c, 0x0e, 0x0e, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(arcade, sizeof(arcade));
    oled_set_cursor(0, 4);
}

void render_arrow(void) {
    static const char PROGMEM arrow [] = {  //32x32
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x30, 0x20, 0x60, 0x20, 0x20, 0xb0, 0x9c, 0x8e, 0x86, 
        0x86, 0x8e, 0x9c, 0xb0, 0x20, 0x20, 0x60, 0x20, 0x30, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xc0, 0xe0, 0x60, 0x30, 0x1f, 0x02, 0xf0, 0x1c, 0x06, 0x03, 0x01, 0x01, 0x00, 0x00, 0xfc, 
        0xfc, 0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x1c, 0xf0, 0x02, 0x1f, 0x30, 0x60, 0xe0, 0xc0, 0x00, 
        0x00, 0x03, 0x07, 0x06, 0x0c, 0xf8, 0x40, 0x0f, 0x38, 0x60, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x33, 
        0x33, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x38, 0x0f, 0x40, 0xf8, 0x0c, 0x06, 0x07, 0x03, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x04, 0x0c, 0x04, 0x06, 0x04, 0x04, 0x0d, 0x39, 0x71, 0x61, 
        0x61, 0x71, 0x39, 0x0d, 0x04, 0x04, 0x06, 0x04, 0x0c, 0x04, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(arrow, sizeof(arrow));
    oled_set_cursor(0, 4);
}

void render_media(void) {
    static const char PROGMEM media [] = {  //32x32
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0c, 0x08, 0x18, 
        0x30, 0x20, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x30, 0x10, 0x18, 
        0x0c, 0x04, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
        0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00 
    };

    oled_write_raw_P(media, sizeof(media));
    oled_set_cursor(0, 4);
}

void render_navigation(void) {
    static const char PROGMEM navigation [] = {  //32x32
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x60, 
        0x60, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x3c, 0x1f, 0x07, 0x01, 0x00, 
        0x00, 0x01, 0x07, 0x1f, 0x7c, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x7c, 0x1e, 0x07, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 
        0xc0, 0x80, 0x80, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x7c, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x06, 0x06, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 
        0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x06, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(navigation, sizeof(navigation));
    oled_set_cursor(0, 4);
}

void render_empty_line(void) {
    oled_write_ln_P(PSTR(""), false);
}

bool oled_timeout_housekeeping(void) {
    // this fixes the screen on and off bug
    if (last_input_activity_elapsed() < CUSTOM_OLED_TIMEOUT) { 
        if(!is_oled_on())
            oled_on();
        return true;
    } 
    oled_off(); 
    return false;
}