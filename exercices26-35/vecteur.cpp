#include "vecteur.h"

Vecteur::Vecteur(unsigned int d, const double *v) : tab(new double[d]), dim(d) {
    if (!v) for (unsigned int i = 0; i < dim; i++) tab[i] = 0;
    else    for (unsigned int j = 0; j < dim; j++) tab[j] = v[j];
}

Vecteur::Vecteur(const Vecteur& vect) : tab(new double[vect.dim]), dim(vect.dim) {
    for (int i = 0; i < vect.dim; i++) tab[i] = vect.tab[i];
}

Vecteur Vecteur::operator+(const Vecteur& vect) const {
    if (dim != vect.dim) throw "erreur dim differentes";
    Vecteur res = *this;
    for (unsigned int i = 0; i < dim; i++) res.tab[i] += vect.tab[i];
    return res;
}

double operator*(const Vecteur& vect1, const Vecteur& vect2) {
    if (vect1.dim != vect2.dim) throw "erreur dim vecteurs";
    double res = 0;
    for (int i = 0; i < vect1.dim; i++) res += vect1.tab[i] * vect2.tab[i];
    return res;
}
