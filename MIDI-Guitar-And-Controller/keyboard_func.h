#ifndef KEYBOARD_FUNC_H
#define KEYBOARD_FUNC_H

#include <Arduino.h>
#include <Keyboard.h>
#include "buttons.h"

/* 
 *  ---------- Keys CH || MODE 1 ----------
 *  BUTTON_GREEN_1               = 'a'
 *  BUTTON_RED_1                 = 's'
 *  BUTTON_YELLOW_1              = 'j'
 *  BUTTON_BLUE_1                = 'k'
 *  BUTTON_ORANGE_1              = 'l'
 *  BUTTON_STRUM_BAR_DOWN        = "Down Arrow"
 *  BUTTON_STRUM_BAR_UP          = "Up Arrow"
 *  BUTTON_WHAMMY_BAR            = ';'
 *  BUTTON_SELECT                = 'h'
 *  ---------------------------------------
 *  ---------- Keys GH || MODE 2 ----------
 *  BUTTON_GREEN_1               = 'A'
 *  BUTTON_RED_1                 = 'S'
 *  BUTTON_YELLOW_1              = 'J'
 *  BUTTON_BLUE_1                = 'K'
 *  BUTTON_ORANGE_1              = "L"
 *  BUTTON_STRUM_BAR_DOWN        = "Down Arrow"
 *  BUTTON_STRUM_BAR_UP          = "Up Arrow"
 *  BUTTON_WHAMMY_BAR            = "Q"
 *  BUTTON_SELECT                = "Space"
 *  ---------------------------------------
 *  ---------- Keys GF || MODE 3 ----------
 *  BUTTON_GREEN_1               = 'a'
 *  BUTTON_RED_1                 = 's'
 *  BUTTON_YELLOW_1              = 'j'
 *  BUTTON_BLUE_1                = 'k'
 *  BUTTON_ORANGE_1              = 'l'
 *  BUTTON_STRUM_BAR_DOWN        = "Space"
 *  BUTTON_STRUM_BAR_UP          = "Space"
 *  BUTTON_WHAMMY_BAR            = "Space"
 *  BUTTON_SELECT                = "Space"
 *  ---------------------------------------
 */
 
#define KEY_SPACE          32
#define KEY_SEMICOLON      59
#define KEY_a              97 
#define KEY_s              115
#define KEY_j              106 
#define KEY_k              107
#define KEY_l              108
#define KEY_h              104
#define KEY_UP_ARROW       218
#define KEY_DOWN_ARROW     217
#define KEY_q              113
#define KEY_w              119


/**
 * \brief Setup the keyboard.
 */
void keyboard_func_init();

/**
 * \brief Change between modes
 * 
 * \param[in] buttons buttons array
 * buttons[0]  = BUTTON_GREEN_1
 * buttons[1]  = BUTTON_RED_1
 * buttons[2]  = BUTTON_YELLOW_1
 * buttons[3]  = BUTTON_BLUE_1
 * buttons[4]  = BUTTON_ORANGE_1
 * buttons[5]  = BUTTON_STRUM_BAR_DOWN
 * buttons[6]  = BUTTON_STRUM_BAR_UP
 * buttons[7]  = BUTTON_WHAMMY_BAR
 * buttons[8]  = BUTTON_SELECT
 * 
 * \param[in] mode changes between game modes
 * 
 * game modes:
 * 1-clone hero
 * 2-guitar hero
 * 3-guitar flash
 */
void keyboard_func_guitar_buttons(int buttons[9], int* mode);

#endif /* KEYBOARD_FUNC_H */
