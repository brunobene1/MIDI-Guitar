#include "midi_func.h"

int whammy_val = 0;              // gets whammy bar value
int last_whammy_val= 0;          // saves last whammy bar value
const uint8_t chordDelay = 15;   // delay between each note of the chord in ms
bool playedChord = 0;            // flag which resets after chord is played
int strum = 0;                   //0 = no strum, 1 = strum up, 2 = strum down

// ----- Individual notes -----
//const byte note_array[5]             = {64, 66, 67, 69, 71};
//const byte note_array[5]             = {E4, G4b, G4, A4, B4};
const byte come_as_you_are[5]        = {E2, F2, G2b, A2, B2};
//const byte beethoven_9_symphony[5]   = {C4, D4, E4, F4, G4};
//const byte seven_nation_army[5]      = {E2, F2, G2, A2, B2};
//const byte smoke_on_the_water[5]     = {G2, B2b, C2, D2b, A2b}; 
//const byte the_last_of_us[5]         = {E4, G4b, G4, A4, B4};
// ----- Individual notes end -----

// ----- chords -----
//const uint8_t greenChord[]             = {36, 40, 43, 48, 52};   // C major
const uint8_t greenChord[]             = {C2, E2, G2, C3, E3};       // C major
const uint8_t redChord[]               = {A1, E2, A2, D3b, E3};      // A major
const uint8_t yellowChord[]            = {G1, B1, D2, G2, B2, G3};   // G major
const uint8_t blueChord[]              = {E1, B1, E2, A2b, B2, E3};  // E major
const uint8_t orangeChord[]            = {D2, A2, D3, G3b};          // D major
// ----- chords end -----

/* ---------- holding ----------
 * holding[0]  = BUTTON_GREEN_1
 * holding[1]  = BUTTON_RED_1
 * holding[2]  = BUTTON_YELLOW_1
 * holding[3]  = BUTTON_BLUE_1
 * holding[4]  = BUTTON_ORANGE_1
 *  ---------------------------------------
 */
bool holding[5] = {false, false, false, false, false};

void noteOn(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void midi_func_play_note()
{
  if(digitalRead(BUTTON_GREEN_1) == 0)
  {
    if(holding[0] == false)
    {
      noteOn(MIDI_CHANNEL, note_array[0], MIDI_INTENSITY);
      MidiUSB.flush();
      holding[0] = true;
    }
  }
  else
  {
    noteOff(MIDI_CHANNEL, note_array[0], 0);
    MidiUSB.flush();
    holding[0] = false;
  }//END green 1
  
  if(digitalRead(BUTTON_RED_1) == 0)
  {
    if(holding[1] == false)
    {
      noteOn(MIDI_CHANNEL, note_array[1], MIDI_INTENSITY);
      MidiUSB.flush();
      holding[1] = true;
    }
  }
  else
  {
    noteOff(MIDI_CHANNEL, note_array[1], 0);
    MidiUSB.flush();
    holding[1] = false;
  }//END red 1
  
  if(digitalRead(BUTTON_YELLOW_1) == 0)
  {
    if(holding[2] == false)
    {
      noteOn(MIDI_CHANNEL, note_array[2], MIDI_INTENSITY);
      MidiUSB.flush();
      holding[2] = true;
    }
  }
  else
  {
    noteOff(MIDI_CHANNEL, note_array[2], 0);
    MidiUSB.flush();
    holding[2] = false;
  }//END yellow 1

  if(digitalRead(BUTTON_BLUE_1) == 0)
  {
    if(holding[3] == false)
    {
      noteOn(MIDI_CHANNEL, note_array[3], MIDI_INTENSITY);
      MidiUSB.flush();
      holding[3] = true;
    }
  }
  else
  {
    noteOff(MIDI_CHANNEL, note_array[3], 0);
    MidiUSB.flush();
    holding[3] = false;
  }//END blue 1
  
  if(digitalRead(BUTTON_ORANGE_1) == 0)
  {
    if(holding[4] == false)
    {
      noteOn(MIDI_CHANNEL, note_array[4], MIDI_INTENSITY);
      MidiUSB.flush();
      holding[4] = true;
    }
  }
  else
  {
    noteOff(MIDI_CHANNEL, note_array[4], 0);
    MidiUSB.flush();
    holding[4] = false;
  }//END orange 1
}


void midi_func_play_chord()
{
  if (digitalRead(BUTTON_GREEN_1) == LOW) 
  {
    if((digitalRead(BUTTON_STRUM_BAR_UP) == 0) || (digitalRead(BUTTON_STRUM_BAR_DOWN) == 0))
    {
      if(holding[0] == false && playedChord == 0)
      {
        for (int i = sizeof(greenChord); i > 0; i--) 
        {
          noteOn(MIDI_CHANNEL, (greenChord[i - 1]), MIDI_INTENSITY);
          MidiUSB.flush();
          delay(chordDelay);
        }
      }
    holding[0] = true;
    playedChord = 1;
    }
  }
  else
  {
    holding[0] = false;
    playedChord = 0;
  }//end green

  if (digitalRead(BUTTON_RED_1) == LOW) 
  {
    if((digitalRead(BUTTON_STRUM_BAR_UP) == 0) || (digitalRead(BUTTON_STRUM_BAR_DOWN) == 0))
    {
      if(holding[1] == false && playedChord == 0)
      {
        for (int i = sizeof(redChord); i > 0; i--) 
        {
          noteOn(MIDI_CHANNEL, (redChord[i - 1]), MIDI_INTENSITY);
          MidiUSB.flush();
          delay(chordDelay);
        }
      }
    holding[1] = true;
    playedChord = 1;
    }
  }
  else
  {
    holding[1] = false;
    playedChord = 0;
  }//end red

  if (digitalRead(BUTTON_YELLOW_1) == LOW) 
  {
    if((digitalRead(BUTTON_STRUM_BAR_UP) == 0) || (digitalRead(BUTTON_STRUM_BAR_DOWN) == 0))
    {
      if(holding[2] == false && playedChord == 0)
      {
        for (int i = sizeof(yellowChord); i > 0; i--) 
        {
          noteOn(MIDI_CHANNEL, (yellowChord[i - 1]), MIDI_INTENSITY);
          MidiUSB.flush();
          delay(chordDelay);
        }
      }
    holding[2] = true;
    playedChord = 1;
    }
  }
  else
  {
    holding[2] = false;
    playedChord = 0;
  }//end yellow

  if (digitalRead(BUTTON_BLUE_1) == LOW) 
  {
    if((digitalRead(BUTTON_STRUM_BAR_UP) == 0) || (digitalRead(BUTTON_STRUM_BAR_DOWN) == 0))
    {
      if(holding[3] == false && playedChord == 0)
      {
        for (int i = sizeof(blueChord); i > 0; i--) 
        {
          noteOn(MIDI_CHANNEL, (blueChord[i - 1]), MIDI_INTENSITY);
          MidiUSB.flush();
          delay(chordDelay);
        }
      }
    holding[3] = true;
    playedChord = 1;
    }
  }
  else
  {
    holding[3] = false;
    playedChord = 0;
  }//end blue

  if (digitalRead(BUTTON_ORANGE_1) == LOW) 
  {
    if((digitalRead(BUTTON_STRUM_BAR_UP) == 0) || (digitalRead(BUTTON_STRUM_BAR_DOWN) == 0))
    {
      if(holding[4] == false && playedChord == 0)
      {
        for (int i = sizeof(orangeChord); i > 0; i--) 
        {
          noteOn(MIDI_CHANNEL, (orangeChord[i - 1]), MIDI_INTENSITY);
          MidiUSB.flush();
          delay(chordDelay);
        }
      }
    holding[4] = true;
    playedChord = 1;
    }
  }
  else
  {
    holding[4] = false;
    playedChord = 0;
  }//end yellow
}

void midi_func_end_chord()
{
  if (playedChord == 0 && holding[0] == false && holding[1] == false && holding[2] == false && holding[3] == false && holding[4] == false) 
  {
    if(holding[0] == false)
    {
      for (int i = 0; i < sizeof(greenChord); i++) 
      {
        noteOff(MIDI_CHANNEL, (greenChord[i]), 0);
      }
    }//end green
    
    if(holding[1] == false)
    {
      for (int i = 0; i < sizeof(redChord); i++)
      {
        noteOff(MIDI_CHANNEL, (redChord[i]), 0);
      }
    }//end red
    
    if(holding[2] == false)
    {
      for (int i = 0; i < sizeof(yellowChord); i++) 
      {
        noteOff(MIDI_CHANNEL, (yellowChord[i]), 0);
      }
    }//end yellow

    if(holding[3] == false)
    {
      for (int i = 0; i < sizeof(blueChord); i++) 
      {
        noteOff(MIDI_CHANNEL, (blueChord[i]), 0);
      }
    }//end blue

    if(holding[4] == false)
    {
      for (int i = 0; i < sizeof(orangeChord); i++) 
      {
        noteOff(MIDI_CHANNEL, (orangeChord[i]), 0);
      }
    }//end orange
    
    MidiUSB.flush();
  }
}

void midi_func_whammy_bar() 
{  

  byte channel = 0xE0;
  int diff = 15;

  whammy_val = analogRead(BUTTON_WHAMMY_BAR);
  int whammy_val_diff = whammy_val - last_whammy_val;

  if (abs(whammy_val_diff) > diff)
  {
    // construct 14 bit pitch bend value
    //int modulation = map(whammy_val, 1023, 935, 0, 8000);931 ---- 0
    int modulation = map(whammy_val, 931, 0, 0, 8000);
    modulation = constrain(modulation, 0, 8000);
    unsigned int change = 0x2000 + modulation;  //  0x2000 == no Change
    byte low = change & 0x7F;
    byte high = change >> 7;

    midiEventPacket_t whammy = {0x0E, 0xE0 | channel, low, high};
    MidiUSB.sendMIDI(whammy);
    MidiUSB.flush();
    last_whammy_val = whammy_val;
  }
  delay(2);
}
