#include "keyboard_func.h"

int ch_whammy;
int ch_last_whammy;

void keyboard_func_init()
{
  Keyboard.begin();
}

void keyboard_func_guitar_buttons(int buttons[9], int* mode)
{
  if(digitalRead(BUTTON_GREEN_1) == 0)
  {
    Keyboard.press(buttons[0]);
  }
  else
  {
    Keyboard.release(buttons[0]);
  }//END green 1
  
  if(digitalRead(BUTTON_RED_1) == 0)
  {
    Keyboard.press(buttons[1]);
  }
  else
  {
    Keyboard.release(buttons[1]);
  }//END red 1

  if(digitalRead(BUTTON_YELLOW_1) == 0)
  {
    Keyboard.press(buttons[2]);
  }
  else
  {
    Keyboard.release(buttons[2]);
  }//END yellow 1

  if(digitalRead(BUTTON_BLUE_1) == 0)
  {
    Keyboard.press(buttons[3]);
  }
  else
  {
    Keyboard.release(buttons[3]);
  }//END blue 1
  
  if(digitalRead(BUTTON_ORANGE_1) == 0)
  {
    Keyboard.press(buttons[4]);
  }
  else
  {
    Keyboard.release(buttons[4]);
  }//END orange 1
  
  if(digitalRead(BUTTON_STRUM_BAR_DOWN) == 0)
  {
    Keyboard.press(buttons[5]);
  }
  else
  {
    Keyboard.release(buttons[5]);
  }//END Strum bar down

  if(digitalRead(BUTTON_STRUM_BAR_UP) == 0)
  {
    Keyboard.press(buttons[6]);
  }
  else
  {
    Keyboard.release(buttons[6]);
  }//END Strum bar up
  
  if(*mode != 1)//if not clone hero mode
  {
    if(analogRead(BUTTON_WHAMMY_BAR) <928)//931 ---- 0
    {
      Keyboard.press(buttons[7]);
    }
    else
    {
      Keyboard.release(buttons[7]);
    }//END Whammy bar
  }
  else //clone hero mode
  {
    ch_whammy = analogRead(BUTTON_WHAMMY_BAR);
    if(ch_whammy <= 928)
    {
      if((ch_whammy - ch_last_whammy) >= 0)
      {
        Keyboard.press(KEY_q);
        Keyboard.release(KEY_w);
      }
      else if((ch_whammy - ch_last_whammy) < 0)
      {
        Keyboard.press(KEY_w);
        Keyboard.release(KEY_q);
      }//END Whammy bar
    }
    else
    {
      Keyboard.release(KEY_q);
      Keyboard.release(KEY_w);
    }
    
    ch_last_whammy = ch_whammy;
  }

  if(digitalRead(BUTTON_SELECT) == 0)
  {
    Keyboard.press(buttons[8]);
  }
  else
  {
    Keyboard.release(buttons[8]);
  }//END select
}
