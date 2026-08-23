#include QMK_KEYBOARD_H

//1. Define our custom macro names
enum custom_keycodes {
    GUMROAD_lINK = SAFE_RANGE
};

//2. The Keymap: This maps the 5 button (4 switches + 1 encoder button)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE,           //Switch 1
        KC_MNXT,           //Switch 2
        LCTL(LGUI(KC_RGHT)),  //Switch 3 (Windows: Next Desktop)
        GUMROAD_lINK,        //Switch 4 (OUR custom macro)
        KC_MPLY              // Encoder Button
    )
};

//3.  Variable to track the cat's animation satate
#ifdef OLED_ENABLE
static uint32_t bongo_timer = 0;
static bool is_bongo_typing = false;
#endif

//4. The Macro Logic: What happens when you press Switch 4
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed)

    //Wake up the cat!
    #ifdef OLED_ENABLE
    bongo_timer = timer_read32();
    is_bongo_typing = true;
    #endif

    if (keycode == GUMROAD_lINK) {
        SEND_STRING("https://notebook.google.com/?authuser=1");
        return false;
    }
    return true;
}

//5. The rotary encoder logic: what happens when you turn the knob
bool encoder_update_user(uint8_t index, bool clockwise) {
    //Wake up the cat when turning the knob!
    #ifdef OLED_ENABLE
    bongo_timer = timer_read32();
    is_bongo_typing = true;
    #endif

    if (clockwise) {
        tap_code(KC_VOLU); //volume up
    } else {
        tap_code(KC_VOLD); // volume down
    }
    return false;
}

//6. The OLED Screen Logic: Drawing the cat
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    //if ot has been more than 300ms since your last press, put the cat to sleep
    if (timer_elapsed32(bongo_timer) > 300) {
        is_bongo_typing = false;
    }

    oled_set_cursor(0, 1);

    if (is_bongo_typing) {
        // frame 1: Typing aggressively
        oled_write_P(PSTR("  /\\_/\\  \n"), false);
        oled_write_P(PSTR("  ( >.< ) \n"), false);
        oled_write_P(PSTR("  />   <\\ \n"), false);
    } else {
        //Frame 2: Resting peacefully
        oled_write_P(PSTR("  /\\_/\\  \n"), false);
        oled_write_P(PSTR("  ( o.o ) \n"), false);
        oled_write_P(PSTR("   >   <  \n"), false);
    }
    return false;
}
#endif
