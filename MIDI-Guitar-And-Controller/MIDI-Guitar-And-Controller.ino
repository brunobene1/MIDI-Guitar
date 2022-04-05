/**
 * \brief MIDI guitar + guitar controller
 * 
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 * 
 * \version 1.0.0
 * 
 * \date 18/02/2022
 * 
 */

#include "buttons.h"
#include "change_modes.h"

void setup()
{
  Serial.begin(9600);
  buttons_setup();
}

void loop()
{
  change_modes();
}
