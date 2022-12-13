#include "SequenceRunner.h"

SequenceRunner::SequenceRunner(Sequence s, int *lamp_toggle, int repetitions=1) :
  sequence(s), lamp_toggle(lamp_toggle), repetitions(repetitions) {
}

void SequenceRunner::run(Tetromino *tetrominos, int n_tets) {

  for (int j = 0; j < repetitions; j++) {
    for (int i = 0; i < sequence.getLength(); i++) {
      // Check lamp_toggle value
      if (!*lamp_toggle) {
        for (int t = 0; t < n_tets; t++) {
          Tetromino tet = *(tetrominos + t);
          tet.on(sequence.getTets(i));
        }

        delay(sequence.getDuration(i));
      }
    }
  }
}