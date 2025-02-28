#include "lecteur.h"

Lecteur::Lecteur()
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
}

void Lecteur::avancer()
{
    _posImageCourante=(_posImageCourante+1) %nbImages();
}

void Lecteur::reculer()
{
    _posImageCourante=(_posImageCourante-1) %nbImages();

}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }

}

void Lecteur::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    Image* imageACharger;
    imageACharger = new Image(3, "personne", "Blanche Neige", "F:/Documents/S2.01_dev_appli/S2.01-master/v2/cartesDisney/Disney_4.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(2, "personne", "Cendrillon", "F:/Documents/S2.01_dev_appli/S2.01-master/v2/cartesDisney/Disney_21.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(4, "animal", "Mickey", "F:/Documents/S2.01_dev_appli/S2.01-master/v2/cartesDisney/Disney_19.gif");
    _diaporama.push_back(imageACharger);
    imageACharger = new Image(1, "personne", "Mulan", "F:/Documents/S2.01_dev_appli/S2.01-master/v2/cartesDisney/Disney_24.gif");
    _diaporama.push_back(imageACharger);


     // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
    //TRAITEMENT
    Image* copieImageParcourue;
    for (unsigned int i = 0 ; i < nbImages() - 1; i++) {
        for (unsigned int j = 0; j < nbImages() - 1; j++) {
            if ( _diaporama[j]->getRang() > _diaporama[j+1]->getRang() )
            {
                //Echanger les images
                copieImageParcourue = _diaporama[j];
                _diaporama[j] = _diaporama[j+1];
                _diaporama[j+1] = copieImageParcourue;
            }
        }
    }

     _posImageCourante = 0;

     cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
     cout << nbImages() << " images chargees dans le diaporama " << endl;

}

void Lecteur::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;

}

void Lecteur::afficher()
{
    /* affiche les information sur le lecteur :
     * 1) vide (si num. de diaporama = 0) OU BIEN  numéro de diaporama affiché */
     if (numDiaporamaCourant() == 0)
     {
         cout << "Lecteur vide" << endl;
     }
     else
     {
        cout << "Diaporama num. " << numDiaporamaCourant() << endl;


    /*
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante OU BIEN 'diaporama vide'
     *     si ce diaporama n'a aucune image */
         if ( numDiaporamaCourant() > 0)
         {
             cout << "Image courante : ";
             imageCourante()->afficher() ;
         }
         else{
             cout << "Diaporama vide";
         }
      }
}

unsigned int Lecteur::nbImages()
{
    return _diaporama.size();
}

Image *Lecteur::imageCourante()
{
    if(_diaporama.empty())
    {
        return nullptr;
    }
    else
    {
       return _diaporama[_posImageCourante];
    }
}

unsigned int Lecteur::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}

