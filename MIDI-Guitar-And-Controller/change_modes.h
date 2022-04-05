#ifndef CHANGE_MODES_H
#define CHANGE_MODES_H

#include <Arduino.h>
#include "buttons.h"
#include "keyboard_func.h"
#include "midi_func.h"

/**
 * \brief Changes between modes
 * 
 * Modes:
 * 1 - Clone Hero
 * 2 - Guitar Hero
 * 3 - Guitar Flash
 * 4 - MIDI guitar
 * 
 * ------ buttons array -----
 * buttons[0]  = BUTTON_GREEN_1
 * buttons[1]  = BUTTON_RED_1
 * buttons[2]  = BUTTON_YELLOW_1
 * buttons[3]  = BUTTON_BLUE_1
 * buttons[4]  = BUTTON_ORANGE_1
 * buttons[5]  = BUTTON_STRUM_BAR_DOWN
 * buttons[6]  = BUTTON_STRUM_BAR_UP
 * buttons[7]  = BUTTON_WHAMMY_BAR
 * buttons[8]  = BUTTON_SELECT
 */
void change_modes();

/**
 * \brief Changes between MIDI modes
 * 
 * single note mode = 0
 * chord mode = 1
 */
void change_modes_MIDI();

/**
 * \brief reads the start button for switching between modes
 */
void change_modes_start_button();

#endif /* CHANGE_MODES_H */
