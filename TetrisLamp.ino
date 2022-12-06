#include "Tetromino.h"
#include "Pulse.h"
#include "SequenceRunner.h"
#include "Sequence.h"
#include "Pulse.h"

// Globals
int n_tets = 14; // Total number of tetrominoes. I have 2 packs of 7 Tetrominoes
Tetromino *tetrominos = (Tetromino*) malloc (n_tets * sizeof(Tetromino)); // Allocate required memory for Tetromino objects
volatile int lamp_toggle = 0; // Flag to determine if we're in full on/sequence mode. Hardware button to change state - GPIO pin 13

void setup() {
  // Initialise GPIO
  // Lamp action toggle - define as interrupt
  attachInterrupt(digitalPinToInterrupt(13), toggle, CHANGE);

  // Right side of board
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  // Left side of the board (14-21)
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);

  // Set up Tetrominos (Right side of the board, top to bottom)
  Tetromino tet_square_1 = Tetromino(12, 1);
  Tetromino tet_s_1 = Tetromino(11, 2);
  Tetromino tet_z_1 = Tetromino(10, 4);
  Tetromino tet_long_1 = Tetromino(9, 8);
  Tetromino tet_t_1 = Tetromino(8, 16);
  Tetromino tet_l1_1 = Tetromino(7, 32);
  Tetromino tet_l2_1 = Tetromino(6, 64);

  // Set up Tetrominos (Left side of the board, top to bottom)
  Tetromino tet_square_2 = Tetromino(14, 128);
  Tetromino tet_s_2 = Tetromino(15, 256);
  Tetromino tet_z_2 = Tetromino(16, 512);
  Tetromino tet_long_2 = Tetromino(17, 1024);
  Tetromino tet_t_2 = Tetromino(18, 2048);
  Tetromino tet_l1_2 = Tetromino(19, 4096);
  Tetromino tet_l2_2 = Tetromino(20, 8192);

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
}

// Here we pass the address(&) of the lamp_toggle variable, a pointer to its value
// so when it changes it is changed globally 
SequenceRunner *runners[1] = {
  new SequenceRunner(Pulse(), &lamp_toggle)
  
};

void loop() {
  runners[0]->run(tetrominos, n_tets);
}

void toggle() { 
  //ISR function
  lamp_toggle = !lamp_toggle; //toggle the state when the interrupt occurs

  for (int t = 0; t < n_tets; t++) {
    Tetromino tet = *(tetrominos + t);
    if (lamp_toggle) {
      tet.on(0xFFFF);
    } else {
      tet.off(0xFFFF);
    }
  }
}