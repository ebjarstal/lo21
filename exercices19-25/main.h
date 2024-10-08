#ifndef LO21_MAIN_H
#define LO21_MAIN_H

#include <iostream>
#include <string>

using namespace std;

enum Genre  { homme, femme };
enum Statut { celibataire, marie, veuf };

class Personne {
private:
    Genre  genre;
    string nom;
    string prenom;
    int    annee_naissance;
    Statut statut;

    Personne* conjoint = nullptr;
public:
    Personne(const Genre g, string n, string p, int a_n, Statut s) :
    genre(g), nom(n), prenom(p), annee_naissance(a_n), statut(s) {}

    ~Personne();

    inline Genre getGenre()        const { return genre; }
    inline string getNom()         const { return nom; }
    inline string getPrenom()      const { return prenom; }
    inline int getAnneeNaissance() const { return annee_naissance; }
    inline Statut getStatut()      const { return statut; }

    unsigned int age(int annee) const;

    void mariageAvec(Personne& c);
    void divorce();
};

ostream& operator<<(ostream& f, Personne& p);

void f();

#endif //LO21_MAIN_H
