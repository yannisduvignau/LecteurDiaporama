#include "LecteurVue.h"
#include "lecteur.h"
#include "image.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue lv;
    lv.show();
    return a.exec();
}
