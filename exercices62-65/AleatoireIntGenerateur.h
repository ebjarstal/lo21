#ifndef LO21_ALEATOIREINTGENERATEUR_H
#define LO21_ALEATOIREINTGENERATEUR_H

#include <string>
#include <cmath>

using namespace std;

class AleatoireIntGenerateur {
    double random() const {
        static unsigned int rootA = 27134;
        static unsigned int rootB =  9213;
        static unsigned int rootC = 17773;
        rootA = (rootA*171) % 30269;
        rootB = (rootB*172) % 30307;
        rootC = (rootC*170) % 30323;
        double x = rootA/30269.0 + rootB/30307.0 + rootC/30323.0;
        return x - floor(x); // retourne la partie décimale (entre 0 et 1)
    }
    string name;
public:
    explicit AleatoireIntGenerateur(const string& n="") : name(n) {}
    unsigned int getInt(unsigned int max) const {
        double x = random()*max;
        if (x - floor(x) > 0.5) return static_cast<int>(ceil(x));
        else                    return static_cast<int>(floor(x));
    }
};

class RandomGenerator {
protected:
    unsigned int max;
public:
    unsigned int getMax() const { return max; }
    explicit RandomGenerator(unsigned int m) : max(m) {}
    // renvoie un nombre aléatoire de {0,...,getMax()}
    virtual unsigned int getNumber() const = 0;
};

class RandomIntGenerator : public RandomGenerator {
private:
    AleatoireIntGenerateur G;
public:
    explicit RandomIntGenerator(unsigned int m) : RandomGenerator(m), G("SIMULA3000") {}
    inline unsigned int getNumber() const { return G.getInt(max); }
};

#endif //LO21_ALEATOIREINTGENERATEUR_H
