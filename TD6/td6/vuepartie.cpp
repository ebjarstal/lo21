#include "vuepartie.h"
#include <QLabel>
#include <QProgressBar>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMessageBox>

VuePartie::VuePartie(QWidget* parent) : QWidget(parent), vuecartes(20, nullptr) {
    for (size_t i = 0; i < 20; i++) vuecartes[i] = new VueCarte;
    controleur.distribuer();
    size_t i = 0;
    for(auto it = controleur.getPlateau().begin(); it != controleur.getPlateau().end(); ++it, i++) {
        vuecartes[i]->setCarte(*it);
    }
    setWindowTitle("Set !");
    pioche = new QLabel("Pioche");
    score = new QLabel("Score");
    // barre de progression de la pioche
    nbCartesPioche = new QProgressBar;
    nbCartesPioche->setRange(0, Set::Jeu::getInstance().getNbCartes());
    nbCartesPioche->setValue(controleur.getPioche().getNbCartes());
    nbCartesPioche->setFixedHeight(30);
    nbCartesPioche->setTextVisible(false); // ne pas afficher le % de la barre de progression

    scoreJoueur = new QLCDNumber;
    scoreJoueur->display(0);
    scoreJoueur->setFixedHeight(30);

    layoutInformations = new QHBoxLayout;
    layoutInformations->addWidget(pioche);
    layoutInformations->addWidget(nbCartesPioche);
    layoutInformations->addWidget(score);
    layoutInformations->addWidget(scoreJoueur);

    layoutCartes = new QGridLayout;
    for (size_t i = 0; i < 20; i++) {
        layoutCartes->addWidget(vuecartes[i], i/4, i%4);
        connect(vuecartes[i], SIGNAL(carteClicked(VueCarte*)), this, SLOT(carteClique(VueCarte*)));
    }

    couche = new QVBoxLayout;
    couche->addLayout(layoutInformations);
    couche->addLayout(layoutCartes);
    setLayout(couche);
}

void VuePartie::carteClique(VueCarte* vc) {
    if (vc->cartePresente()) {
        if (vc->isChecked()) {
            selectionCartes.insert(&vc->getCarte());
            if (selectionCartes.size() == 3) {
                vector<const Set::Carte*> c(selectionCartes.begin(), selectionCartes.end());
                Set::Combinaison comb(*c[0], *c[1], *c[2]);
                if (comb.estUnSET()) {
                    controleur.getPlateau().retirer(*c[0]);
                    controleur.getPlateau().retirer(*c[1]);
                    controleur.getPlateau().retirer(*c[2]);
                    selectionCartes.clear();
                    if (controleur.getPlateau().getNbCartes() < 12) controleur.distribuer();
                    // mise à jour affichage du plateau et score
                    scoreValue++;
                    scoreJoueur->display(scoreValue);
                    // => nettoyage d'abor pour compacter
                    for (size_t i = 0; i < vuecartes.size(); i++) vuecartes[i]->setNoCarte();
                    size_t i = 0;
                    for (auto it = controleur.getPlateau().begin(); it != controleur.getPlateau().end(); ++it, i++) {
                        vuecartes[i]->setCarte(*it);
                    }
                } else {
                    QMessageBox message(QMessageBox::Icon::Warning, "Attention", "Ce n'est pas un set !");
                    message.exec();
                    for (size_t i = 0; i < vuecartes.size(); i++) vuecartes[i]->setChecked(false);
                    selectionCartes.clear();
                }
            }
        } else {
            selectionCartes.erase(&vc->getCarte());
        }
    } else {
        size_t n = controleur.getPioche().getNbCartes();
        if (n == 0) {
            QMessageBox message(QMessageBox::Icon::Warning, "Attention", "La pioche est vide");
            message.exec();
        }
        nbCartesPioche->setValue(n);
        controleur.distribuer();
        size_t i = 0;
        for (auto it = controleur.getPlateau().begin(); it != controleur.getPlateau().end(); ++it, i++) {
            vuecartes[i]->setCarte(*it);
        }
    }
    update();
}
