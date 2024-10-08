#include "main.h"

Personne::~Personne() {
    if (conjoint) {
        if (conjoint->statut == marie) {
            conjoint->statut = veuf;
        }
        else {
            conjoint->statut = celibataire;
        }
        conjoint->conjoint = nullptr;
    }
}

ostream& operator<<(ostream& f, Personne& p) {
    f << (p.getGenre() == homme ? "M. " : "Mme ")
    << p.getNom()
    << " "
    << p.getPrenom()
    << " est "
    << (p.getGenre() == homme ? "ne " : "nee ")
    << "en "
    << p.getAnneeNaissance()
    << ", "
    << (p.getGenre() == homme ? "il " : "elle ")
    << "est ";

    switch(p.getStatut()) {
        case celibataire: f << "celibataire";                                  break;
        case marie:       f << (p.getGenre() == homme ? "marie " : "mariee "); break;
        case veuf:        f << (p.getGenre() == homme ? "veuf " : "veuve ");   break;
    }

    return f;
}

unsigned int Personne::age(int annee) const {
    int age = annee - annee_naissance;
    return age < 0 ? 0 : age;
}

void Personne::mariageAvec(Personne& c) {
    if (statut == marie || c.statut == marie) {
        cout << "Au moins une des personnes est deja mariee" << endl;
        return;
    }
    conjoint = &c;
    c.conjoint = this;
    statut = marie;
    c.statut = marie;
}

void Personne::divorce() {
    if (statut != marie || !conjoint) {
        cout << "Cette personne n est pas mariee" << endl;
        return;
    }
    statut = celibataire;
    conjoint->statut = celibataire;
    conjoint->conjoint = nullptr;
    conjoint = nullptr;
}

void f() {
    auto* pt = new Personne(homme, "Tapoche", "David", 1984, veuf);
    cout << *pt << endl;
    delete pt;
}

void test() {
    auto* p1 = new Personne(homme, "Rition", "Gaspard", 1998, celibataire);
    auto* p2 = new Personne(femme, "Aufrese", "Charlotte", 1985, veuf);
    cout << *p1 << endl;
    cout << *p2 << endl;
    p1->mariageAvec(*p2);
    cout << *p1 << endl;
    cout << *p2 << endl;
    p2->divorce();
    cout << *p1 << endl;
    cout << *p2 << endl;
    p2->mariageAvec(*p1);
    delete(p1);
    cout << *p2 << endl;
    delete(p2);
}

int main() {
    f();
    test();
    return 0;
}
