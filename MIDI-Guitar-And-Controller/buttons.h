#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

// ----- Pins buttons 1 -----
#define BUTTON_GREEN_1             2
#define BUTTON_RED_1               3
#define BUTTON_YELLOW_1            4
#define BUTTON_BLUE_1              5
#define BUTTON_ORANGE_1            6
// ----- Pins buttons 2 -----
#define BUTTON_GREEN_2             1
#define BUTTON_RED_2               2
#define BUTTON_YELLOW_2            8
#define BUTTON_BLUE_2              9
#define BUTTON_ORANGE_2            10
// ----- Pins other buttons -----
#define BUTTON_STRUM_BAR_DOWN      10
#define BUTTON_STRUM_BAR_UP        9
#define BUTTON_START               7
#define BUTTON_SELECT              8
#define BUTTON_WHAMMY_BAR          A0

/**
 * \brief Setup the buttons pins.
 */
void buttons_setup();

/**
 * \brief Reads the buttons inputs and shows on the serial monitor witch button has been pressed
 */
void buttons_debug();

#endif /* BUTTONS_H */
