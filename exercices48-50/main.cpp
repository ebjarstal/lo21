#include "erreur.h"

void f() {
    throw Erreur("Declenchement d une exception");
}

void g() {
    try {
        f();
    }
    catch(Erreur err) {
        cout << err.getInfo() << endl;
    }
}

int main() {
    g();
    return 0;
}