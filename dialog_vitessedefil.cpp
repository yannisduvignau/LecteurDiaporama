#include "dialog_vitessedefil.h"
#include "ui_dialog_vitessedefil.h"
#include <QDebug>

Dialog_vitesseDefil::Dialog_vitesseDefil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_vitesseDefil)
{
    ui->setupUi(this);

    //Connexions
    QObject::connect(ui->rb_vitesseX1,SIGNAL(clicked()),this,SLOT(vitessex1()));
    QObject::connect(ui->rb_vitesseX2,SIGNAL(clicked()),this,SLOT(vitessex2()));
    QObject::connect(ui->rb_vitesseX5,SIGNAL(clicked()),this,SLOT(vitessex5()));
    QObject::connect(ui->rb_vitesseX10,SIGNAL(clicked()),this,SLOT(vitessex10()));
    QObject::connect(ui->b_quitter,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(ui->b_ok,SIGNAL(clicked()),this,SLOT(close()));

    //Initialiser
    if(lv->getVitesse()==5000){
        ui->rb_vitesseX1->setChecked(true);
    }
    if(lv->getVitesse()==1000){
        ui->rb_vitesseX2->setChecked(true);
    }
    if(lv->getVitesse()==2500){
        ui->rb_vitesseX5->setChecked(true);
    }
    if(lv->getVitesse()==500){
        ui->rb_vitesseX10->setChecked(true);
    }
}

Dialog_vitesseDefil::~Dialog_vitesseDefil()
{
    delete ui;
}

void Dialog_vitesseDefil::vitessex1()
{
    // vitesse de diaporama mis a jour
    _vitesseDiapo = 5000;
    qDebug() << "Vitesse de dialoq changé à :"+ QString::number(_vitesseDiapo);
}

void Dialog_vitesseDefil::vitessex2()
{
    // vitesse de diaporama mis a jour
    _vitesseDiapo = 2500;
    qDebug()<< "vitesse sur dialog changé : "+ QString::number(_vitesseDiapo);

}

void Dialog_vitesseDefil::vitessex5()
{
    // vitesse de diaporama mis a jour
    _vitesseDiapo = 1000;
    qDebug()<< "vitesse sur dialog changé : "+ QString::number(_vitesseDiapo);

}

void Dialog_vitesseDefil::vitessex10()
{
    // vitesse de diaporama mis a jour
    _vitesseDiapo = 500;
    qDebug()<< "vitesse sur dialog changé : "+ QString::number(_vitesseDiapo);

}

int Dialog_vitesseDefil::getVitesse()
{
    return _vitesseDiapo;
}



