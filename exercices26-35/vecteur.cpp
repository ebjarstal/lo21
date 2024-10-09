#include "vecteur.h"

unsigned int Vecteur::nb_instances = 0;

Vecteur::Vecteur(unsigned int d, const double *v) : tab(new double[d]), dim(d) {
    if (!v) for (unsigned int i = 0; i < dim; i++) tab[i] = 0;
    else    for (unsigned int j = 0; j < dim; j++) tab[j] = v[j];
    nb_instances++;
}

Vecteur::Vecteur(const Vecteur& vect) : tab(new double[vect.dim]), dim(vect.dim) {
    for (int i = 0; i < vect.dim; i++) tab[i] = vect.tab[i];
    nb_instances++;
}

Vecteur Vecteur::operator+(const Vecteur& vect) const {
    if (dim != vect.dim) throw "erreur dim differentes";
    Vecteur res = *this;
    for (unsigned int i = 0; i < dim; i++) res.tab[i] += vect.tab[i];
    return res;
}

// on veut que *this ait les mêmes attributs que vect
Vecteur& Vecteur::operator=(const Vecteur& vect) {
    if (this != &vect) {
        delete[] tab;
        dim = vect.dim;
        tab = new double[dim];
        for (int i = 0; i < dim; i++) tab[i] = vect.tab[i];
    }
    return *this;
}

const double& Vecteur::operator[](unsigned int i) const {
    if (i >= dim || tab == nullptr) throw "i>dim ou tab null";
    return tab[i];
}

double operator*(const Vecteur& vect1, const Vecteur& vect2) {
    if (vect1.dim != vect2.dim) throw "erreur dim vecteurs";
    double res = 0;
    for (int i = 0; i < vect1.dim; i++) res += vect1.tab[i] * vect2.tab[i];
    return res;
}
