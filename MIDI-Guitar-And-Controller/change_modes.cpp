#include "change_modes.h"

int mode = 1;
int MIDI_mode = 0;
int buttons[9]; //buttons array

void change_modes()
{
  switch(mode)
  {
    case 1://1-Clone Hero
    //Serial.println("Clone Hero mode");
    change_modes_start_button();
    buttons[0]   = KEY_a;
    buttons[1]   = KEY_s;
    buttons[2]   = KEY_j;
    buttons[3]   = KEY_k;
    buttons[4]   = KEY_l;
    buttons[5]   = KEY_DOWN_ARROW;
    buttons[6]   = KEY_UP_ARROW;
    buttons[7]   = KEY_SEMICOLON;
    buttons[8]   = KEY_h;
    keyboard_func_guitar_buttons(buttons, &mode);      
    break;
    
    case 2://2-Guitar Hero
    //Serial.println("Guitar Hero mode");
    change_modes_start_button();
    buttons[0]   = KEY_a;
    buttons[1]   = KEY_s;
    buttons[2]   = KEY_j;
    buttons[3]   = KEY_k;
    buttons[4]   = KEY_l;
    buttons[5]   = KEY_DOWN_ARROW;
    buttons[6]   = KEY_UP_ARROW;
    buttons[7]   = KEY_q;
    buttons[8]   = KEY_SPACE;
    keyboard_func_guitar_buttons(buttons, &mode);
    break;
      
    case 3://3-Guitar Flash
    //Serial.println("Guitar Flash mode");
    change_modes_start_button();
    buttons[0]   = KEY_a;
    buttons[1]   = KEY_s;
    buttons[2]   = KEY_j;
    buttons[3]   = KEY_k;
    buttons[4]   = KEY_l;
    buttons[5]   = KEY_SPACE;
    buttons[6]   = KEY_SPACE;
    buttons[7]   = KEY_SPACE;
    buttons[8]   = KEY_SPACE;
    keyboard_func_guitar_buttons(buttons, &mode);
    break;

    case 4://4-MIDI guitar
    //Serial.println("MIDI mode");
    change_modes_start_button();
    change_modes_MIDI();
    if(MIDI_mode == 0)//single note mode
    {
      midi_func_play_note();
      midi_func_whammy_bar();
    }
    else//chord mode
    {
      midi_func_play_chord();
      midi_func_end_chord();
    }
    break;

    default:
    mode = 1;
    break;
    
  }
}

void change_modes_MIDI()
{
  if(digitalRead(BUTTON_SELECT) == 0)
  {
    MIDI_mode++;
    delay(350);
  }
  if(MIDI_mode == 2)
  {
    MIDI_mode =0;
    delay(350);
  }
}

void change_modes_start_button()
{
  if(digitalRead(BUTTON_START) == 0)
  {
    mode++;
    delay(350);
  }
  if(mode == 5) //There are 4 modes, so mode = 5 goes back to mode = 1
  {
    mode = 1;
    delay(350);
  }
}
