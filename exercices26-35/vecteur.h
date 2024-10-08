#ifndef LO21_VECTEUR_H
#define LO21_VECTEUR_H

#include <iostream>

using namespace std;

class Vecteur {
private:
    double* tab;
    unsigned int dim;
public:
    explicit Vecteur(unsigned int d, const double *v = nullptr);
    // empêche conversion implicite si seul d est donné en argument
    Vecteur(const Vecteur& vect);
    ~Vecteur() { delete[] tab; }

    Vecteur operator+(const Vecteur& vect) const;

    friend double operator*(const Vecteur& vect1, const Vecteur& vect2);
};

double operator*(const Vecteur& vect1, const Vecteur& vect2);

#endif //LO21_VECTEUR_H
