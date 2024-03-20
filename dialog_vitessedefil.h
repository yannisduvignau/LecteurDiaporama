#ifndef DIALOG_VITESSEDEFIL_H
#define DIALOG_VITESSEDEFIL_H

#include <QDialog>
#include "LecteurVue.h"

namespace Ui {
class Dialog_vitesseDefil;
}

class Dialog_vitesseDefil : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog_vitesseDefil(QWidget *parent = nullptr);
    ~Dialog_vitesseDefil();
    int getVitesse();//permet de récupérer la vitesse changé ou pas
public slots:
    void vitessex1();//si cliqué alors vitesse = 5000
    void vitessex2();//si cliqué alors vitesse = 5000/2 = 2500
    void vitessex5();//si cliqué alors vitesse = 5000/5 = 1000
    void vitessex10();//si cliqué alors vitesse = 5000/10 = 500



private:
    Ui::Dialog_vitesseDefil *ui;
    LecteurVue* lv = new LecteurVue(); //création d'un nouvel object LecteurVue
    int _vitesseDiapo; //vitesse du diapo à changer
};

#endif // DIALOG_VITESSEDEFIL_H
