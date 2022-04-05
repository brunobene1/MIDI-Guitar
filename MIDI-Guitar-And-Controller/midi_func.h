#ifndef MIDI_FUNC_H
#define MIDI_FUNC_H

#include <Arduino.h>
#include "buttons.h"
#include "MIDIUSB.h"
#include "pitch_to_note.h"

#define MIDI_CHANNEL 0
#define MIDI_INTENSITY 100

/**
 * \brief sends a MIDI note
 * 
 * \param[in] channel is the MIDI channel(Channel can be anything between 0-15. Typically reported to the user as 1-16).
 * 
 * \param[in] pitch is the note number(Example: 48 = middle C).
 * 
 * \param[in] velocity is the intensity(volume) of the sound (64 = normal, 127 = fastest).
 */
void noteOn(byte channel, byte pitch, byte velocity);

/**
 * \brief sends the end of a MIDI note
 * 
 * \param[in] channel is the MIDI channel(Channel can be anything between 0-15. Typically reported to the user as 1-16).
 * 
 * \param[in] pitch is the note number(Example: 48 = middle C).
 * 
 * \param[in] velocity is the intensity(volume) of the sound (64 = normal, 127 = fastest).
 */
void noteOff(byte channel, byte pitch, byte velocity);

/**
 * \brief sends MIDI to the DAW to play a certain note
 */
void midi_func_play_note();

/**
 * \brief sends a MIDI chord to the DAW
 * 
 * function made by: SwitchAndLever
 * 
 * https://github.com/SwitchAndLever/midiHero/blob/master/code/midiHero/chords.ino
 * 
 * modified by: Bruno Benedetti
 */
void midi_func_play_chord();

/**
 * \brief end strum notes
 * 
 * function made by: SwitchAndLever
 * 
 * https://github.com/SwitchAndLever/midiHero/blob/master/code/midiHero/chords.ino
 * 
 * modified by: Bruno Benedetti
 */
void midi_func_end_chord();

/**
 * \brief reads the whammy bar and changes the pitch value
 * 
 * function made by: SwitchAndLever
 * 
 * https://github.com/SwitchAndLever/midiHero/blob/master/code/midiHero/whammy.ino
 * 
 * modified by: Bruno Benedetti
 */
void midi_func_whammy_bar();

#endif /* MIDI_FUNC_H */
