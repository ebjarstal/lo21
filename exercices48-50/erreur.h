#ifndef LO21_ERREUR_H
#define LO21_ERREUR_H

#include <string>

using namespace std;

class Erreur {
private:
    string info;
public:
    explicit Erreur(const string& x) : info(x) {}

    inline string getInfo() const { return info; }
};

#endif //LO21_ERREUR_H
