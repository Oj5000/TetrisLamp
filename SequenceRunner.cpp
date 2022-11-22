#include "SequenceRunner.h"

SequenceRunner::SequenceRunner(Sequence s) :
  sequence(s) {

}

void SequenceRunner::run(Tetromino *tetrominos, int n_tets) {

  for (int i = 0; i < sequence.getLength(); i++) {

    for (int t = 0; t < n_tets; t++) {
      Tetromino tet = *(tetrominos + t);
      tet.on(sequence.getTets(i));
    }

    delay(sequence.getDuration(i));
  }

}