#include "Sequence.h"

Sequence::Sequence() {

}

int Sequence::getLength() {
  return seqLength;
}

unsigned int Sequence::getTets(int pos){
  return *(tets + pos);
}

unsigned int Sequence::getDuration(int pos) {
  return *(duration + pos);
}