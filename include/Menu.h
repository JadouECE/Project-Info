#ifndef MENU_H
#define MENU_H
#include "grman.h"
#include <iostream>
#include <stack>
#include "Affichage.h"

class Menu
{
    friend class Affichage;

public:
    Menu();
    virtual ~Menu();
    void update();




    /// Utiliser une top_box de type WidgetBox pour encapsuler
    /// tous les éléments de l'interface associés à votre objet
    grman::WidgetBox m_top_box;

    ///Fond de l'interface
    grman::WidgetBox m_fondMenu;

    ///Image du menu
    grman::WidgetImage m_evolve;


    grman::WidgetBox m_boite_bouton1; /// Sera la boite à boutons en bas à gauche
    grman::WidgetButton m_bouton1;  ///bouton1 pour graphe 1
    grman::WidgetImage m_bouton1_image; /// L'image du bouton graphe1

    grman::WidgetBox m_boite_bouton2; /// Sera la boite à boutons en bas au milieu
    grman::WidgetButton m_bouton2;  ///bouton2 pour graphe 2
    grman::WidgetImage m_bouton2_image; /// L'image du bouton graphe2

    grman::WidgetBox m_boite_bouton3; /// Sera la boite à boutons en bas à droite
    grman::WidgetButton m_bouton3;  ///bouton3 pour grapbe 3
    grman::WidgetImage m_bouton3_image; /// L'image du bouton graphe3

    int m_x_evolve;
    int m_y_evolve;
};

#endif // MENU_H
