#ifndef SEQUENCE_H
#define SEQUENCE_H

// Storage class for sequence definitions
class Sequence {

  protected:
    unsigned int *tets; // Unsigned int can store 8 bits and be bit-wise compared
    unsigned int *duration;
    int seqLength;

  public:
   Sequence();
   int getLength();
   unsigned int getTets(int pos);
   unsigned int getDuration(int pos);
   void reset();
};

#endif