#include <iostream>

using namespace std;

struct Date {
    unsigned int jour, mois, annee;
    Date() { jour = 0; mois = 0; annee = 0; }
};

ostream& operator<<(ostream& f, Date& d) {
    f << d.jour << "." << d.mois << "." << d.annee;
    return f;
}

// modification par valeur
Date modifierDate_val(Date d, unsigned int j, unsigned int m, unsigned int a) {
    d.jour = j; d.mois = m; d.annee = a;
    return d;
}

// modification par adresse
void modifierDate_pt(Date* d, unsigned int j, unsigned int m, unsigned int a) {
    d->jour = j; d->mois = m; d->annee = a;
}

// modification par référence
void modifierDate_ref(Date& d, unsigned int j, unsigned int m, unsigned int a) {
    d.jour = j; d.mois = m; d.annee = a;
}

int main() {
    Date d;
    d = modifierDate_val(d, 26, 05, 2003);
    cout << d << endl;
    modifierDate_pt(&d, 26, 05, 2003);
    cout << d << endl;
    modifierDate_ref(d, 26, 05, 2003);
    cout << d << endl;
    return 0;
}
