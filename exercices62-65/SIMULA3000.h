#ifndef LO21_SIMULA3000_H
#define LO21_SIMULA3000_H

#include "AleatoireIntGenerateur.h"

class Simula3000 {
    RandomGenerator* gen;
public:
    Simula3000() : gen(nullptr) {}
    void set_generateur(RandomGenerator& G) { gen = &G; }
};

#endif //LO21_SIMULA3000_H
