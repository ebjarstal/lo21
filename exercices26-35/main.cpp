#include "vecteur.h"

void test1() {
    double tab1[4] = {1, 1.23, 4.703, -3};
    Vecteur v1(4, tab1);
    double tab2[4] = {-1, 0, 4.703, 4.3};
    Vecteur v2(4, tab2);
    Vecteur somme = v1 + v2;
    double produit = v1 * v2;
    cout << produit << endl;
}

void test2() {
    cout << Vecteur::getNbInstances() << endl;  // 0
    Vecteur v1(3);
    cout << Vecteur::getNbInstances() << endl;  // 1
    double tab[2] = {12.3, 0.432};
    Vecteur v2(2, tab);
    cout << Vecteur::getNbInstances() << endl;  // 2
    Vecteur v3(v2);
    cout << Vecteur::getNbInstances() << endl;  // 3
    auto* v4 = new Vecteur(2);
    cout << Vecteur::getNbInstances() << endl;  // 4
    delete v4;
    cout << Vecteur::getNbInstances() << endl;  // 3
    cout << v3.getNbInstances() << endl;        // 3
}

int main() {
    test1();
    test2();
    return 0;
}