#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "lecteur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

public slots:

    //Déclaration des boutons

    void avancer();//avancer d'une image
    void reculer();//reculer d'une image
    void lancerDiapo();//lancement du mode auto
    void arreterDiapo();//areter le mode auto et repasser en mode manuel
    void cb_cat1(bool);//choix de catégorie 1
    void cb_cat2(bool);//choix de catégorie 2
    void cb_cat3(bool);//choix de catégorie 4

    //Déclaration des éléments du menu

    void chargerDiapo();//permet de charger un diaporama
    void changerVitesse();//permet de changer la vitesse de défilement du diapo
    int getVitesse();//récupérer la vitesse de défilement
    void enleverDiapo();//enlever le diapo chargé précédemment
    void aPropos();


private:

    Ui::LecteurVue *ui;
    Lecteur* L = new Lecteur();//création d'un nouvel object Lecteur
    QString rang_Image;//rang de l'image à afficher
    QString nbImage;//nombre d'image total du diaporama à afficher
    QString titreImage;//titre de l'image à afficher
    QString cheminImage;//chemin de l'image à afficher
    QTimer *_timer;
    int _vitesseDefil;//vitesse de défilement courant

};
#endif // LECTEURVUE_H
