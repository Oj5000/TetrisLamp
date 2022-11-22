#ifndef SEQUENCE_RUNNER_H
#define SEQUENCE_RUNNER_H

#include "Arduino.h"
#include "Sequence.h"
#include "Tetromino.h"

class Sequence;

/**
* This class is in charge of reading and performing the patterns
* with the Tetrominos
*/
class SequenceRunner {

  private:
    // Dynamically allocate memory whilst reading the file
    /**
    * We know all values here will be int
    * the file will be a csv of two columns, one for tetromino ID bit value and the other for duration in ms
    * Created as a pointer to the data so we can dynamically allocate the right amount of memory and don't have to shovel it around
    */
    Sequence sequence;

  public:
    SequenceRunner(Sequence sequence);
    void run(Tetromino *tetrominos, int n_tets);
};

#endif