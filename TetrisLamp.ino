#include "Tetromino.h"
#include "Pulse.h"
#include "SequenceRunner.h"
#include "Sequence.h"
#include "Pulse.h"

// Globals
int n_tets = 8; // Remember to update this when adding new tetrominos
Tetromino *tetrominos = (Tetromino*) malloc (n_tets * sizeof(Tetromino));

void setup() {
  // Initialise GPIO
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  // Set up Tetrominos (Right side of the board, top to bottom)
  Tetromino tet_internal = Tetromino(LED_BUILTIN, 128);
  Tetromino tet_square = Tetromino(12, 1);
  Tetromino tet_s = Tetromino(11, 2);
  Tetromino tet_z = Tetromino(10, 4);
  Tetromino tet_long = Tetromino(9, 8);
  Tetromino tet_t = Tetromino(8, 16);
  Tetromino tet_l1 = Tetromino(7, 32);
  Tetromino tet_l2 = Tetromino(6, 64);

  tetrominos[0] = tet_square;
  tetrominos[1] = tet_s;
  tetrominos[2] = tet_z;
  tetrominos[3] = tet_long;
  tetrominos[4] = tet_t;
  tetrominos[5] = tet_l1;
  tetrominos[6] = tet_l2;
  tetrominos[7] = tet_internal;
}

SequenceRunner *runners[1] = {new SequenceRunner(Pulse())};

void loop() {
  runners[0]->run(tetrominos, n_tets);
}
