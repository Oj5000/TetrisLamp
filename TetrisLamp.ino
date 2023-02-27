/*
-**-------			-**-------
--*---****			--32--**8*
--*-------			--*-------
-*-**--*--			-*-1*--*--
**-**--**-			*4-**--*2-
*---**--*-			*---**--*-
*----**-*-			*---256-*-
**----***-			16----*64-
*-*--*--**			*-1--8--128
--*--**-**			--0--19-**
--*---*---			--2---2---
--*---***-			--4---512-
---*----*-			---4----*-
---*--*---			---0--2---
--**-***--			--96-048--
*/

#include "Tetromino.h"
#include "Pulse.h"
#include "SequenceRunner.h"
#include "Sequence.h"
#include "Pulse.h"
#include "Wave.h"
#include "Rain.h"
#include "RandomTetromino.h"

// Globals
const int buttonPin = 3; 

int n_tets = 14; // Total number of tetrominoes. I have 2 packs of 7 Tetrominoes
Tetromino *tetrominos = (Tetromino*) malloc (n_tets * sizeof(Tetromino)); // Allocate required memory for Tetromino objects
volatile int lamp_toggle = 0; // Flag to determine if we're in full on/sequence mode. Hardware button to change state - GPIO pin 13
boolean buttonState = LOW; 

int n_runners = 4;
SequenceRunner *runners = (SequenceRunner*) malloc (n_runners * sizeof(SequenceRunner));

void setup() {
  // Initialise GPIO
  // Lamp action toggle - define as interrupt
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggle, RISING);

  // Right side of board (Digital pins)
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);

  // Left side of the board (14-19) Analogue pins A0-A5
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  
  // Set up Tetrominos (Right side of the board, top to bottom)
  Tetromino tet_square_1 = Tetromino(2, 1);
  Tetromino tet_s_1 = Tetromino(14, 2);
  Tetromino tet_z_1 = Tetromino(18, 4);
  Tetromino tet_long_1 = Tetromino(15, 8);
  Tetromino tet_t_1 = Tetromino(9, 16);
  Tetromino tet_l1_1 = Tetromino(16, 32);
  Tetromino tet_l2_1 = Tetromino(17, 64);
  Tetromino tet_l2_2 = Tetromino(11, 8192);
  Tetromino tet_l1_2 = Tetromino(7, 4096);

  // Set up Tetrominos (Left side of the board, top to bottom)
  Tetromino tet_square_2 = Tetromino(5, 128);
  Tetromino tet_s_2 = Tetromino(6, 256);
  Tetromino tet_z_2 = Tetromino(8, 512);
  Tetromino tet_long_2 = Tetromino(12, 1024);
  Tetromino tet_t_2 = Tetromino(10, 2048);

  tetrominos[0] = tet_square_1;
  tetrominos[1] = tet_s_1;
  tetrominos[2] = tet_z_1;
  tetrominos[3] = tet_long_1;
  tetrominos[4] = tet_t_1;
  tetrominos[5] = tet_l1_1;
  tetrominos[6] = tet_l2_1;

  tetrominos[7] = tet_square_2;
  tetrominos[8] = tet_s_2;
  tetrominos[9] = tet_z_2;
  tetrominos[10] = tet_long_2;
  tetrominos[11] = tet_t_2;
  tetrominos[12] = tet_l1_2;
  tetrominos[13] = tet_l2_2;

  // Here we pass the address(&) of the lamp_toggle variable, a pointer to its value
  // so when it changes it is changed globally and can be visible in the sequences
  runners[0] = SequenceRunner(Pulse(), &lamp_toggle, 2);
  runners[1] = SequenceRunner(Wave(), &lamp_toggle, 5);
  runners[2] = SequenceRunner(Rain(), &lamp_toggle, 5);
  runners[3] = SequenceRunner(RandomTetromino(), &lamp_toggle, 1);
}

void loop() {
  for (int runner = 0; runner < n_runners; runner++) {
    runners[runner].run(tetrominos, n_tets);
  }

  // Re-randomise the random pattern, overwriting the old
  runners[3] = SequenceRunner(RandomTetromino(), &lamp_toggle, 1);
}

void toggle() { 
  //ISR function
  if(debounceButton(buttonState) == HIGH && buttonState == LOW) {
    lamp_toggle = 1; //toggle the state when the interrupt occurs
    buttonState = HIGH;

    for (int t = 0; t < n_tets; t++) {
      Tetromino tet = *(tetrominos + t);
      tet.on(0xFFFF);
    }    
  }
  else if(debounceButton(buttonState) == HIGH && buttonState == HIGH) {
    lamp_toggle = 0;
    buttonState = LOW;

    for (int t = 0; t < n_tets; t++) {
      Tetromino tet = *(tetrominos + t);
      tet.off(0xFFFF);
    }  
  }
}

boolean debounceButton(boolean state) {
  boolean stateNow = digitalRead(buttonPin);

  if(state!=stateNow) {
    delay(100);
    stateNow = digitalRead(buttonPin);
  }

  return stateNow;
}