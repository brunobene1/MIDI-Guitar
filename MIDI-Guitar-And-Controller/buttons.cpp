#include "buttons.h"

void buttons_setup()
{
  pinMode(BUTTON_GREEN_1             , INPUT_PULLUP);
  pinMode(BUTTON_RED_1               , INPUT_PULLUP);
  pinMode(BUTTON_YELLOW_1            , INPUT_PULLUP);
  pinMode(BUTTON_BLUE_1              , INPUT_PULLUP);
  pinMode(BUTTON_ORANGE_1            , INPUT_PULLUP);
  pinMode(BUTTON_STRUM_BAR_DOWN      , INPUT_PULLUP);
  pinMode(BUTTON_STRUM_BAR_UP        , INPUT_PULLUP);
  pinMode(BUTTON_START               , INPUT_PULLUP);
  pinMode(BUTTON_SELECT              , INPUT_PULLUP);
  pinMode(BUTTON_WHAMMY_BAR          , INPUT);
}


void buttons_debug()
{
  if(digitalRead(BUTTON_GREEN_1) == 0)
  {
    Serial.print("Button Green 1 : ");
    Serial.println(BUTTON_GREEN_1);
  }//END green 1
  
  if(digitalRead(BUTTON_RED_1) == 0)
  {
    Serial.print("Button Red 1 : ");
    Serial.println(BUTTON_RED_1);
  }//END red 1
  
  if(digitalRead(BUTTON_YELLOW_1) == 0)
  {
    Serial.print("Button Yellow 1 : ");
    Serial.println(BUTTON_YELLOW_1);
  }//END yellow 1
  
  if(digitalRead(BUTTON_BLUE_1) == 0)
  {
    Serial.print("Button Blue 1 : ");
    Serial.println(BUTTON_BLUE_1);
  }//END blue 1
  
  if(digitalRead(BUTTON_ORANGE_1) == 0)
  {
    Serial.print("Button Orange 1 : ");
    Serial.println(BUTTON_ORANGE_1);
  }//END orange 1

  if(digitalRead(BUTTON_STRUM_BAR_DOWN) == 0)
  {
    Serial.print("Button Strum bar down : ");
    Serial.println(BUTTON_STRUM_BAR_DOWN);
  }//END Strum bar down

  if(digitalRead(BUTTON_STRUM_BAR_UP) == 0)
  {
    Serial.print("Button Strum bar up : ");
    Serial.println(BUTTON_STRUM_BAR_UP);
  }//END Strum bar up

  if(digitalRead(BUTTON_START) == 0)
  {
    Serial.print("Button Start : ");
    Serial.println(BUTTON_START);
  }//END Start

  if(digitalRead(BUTTON_SELECT) == 0)
  {
    Serial.print("Button Select : ");
    Serial.println(BUTTON_SELECT);
  }//END Select
  
  if(analogRead(BUTTON_WHAMMY_BAR) < 928)//931 ---- 0
  {
    Serial.print("Button Whammy bar : ");
    Serial.println(BUTTON_WHAMMY_BAR);
    Serial.print("Values : ");
    Serial.println(analogRead(BUTTON_WHAMMY_BAR));
  }//END Whammy bar
  
}
