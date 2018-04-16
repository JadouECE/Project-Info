#ifndef AFFICHAGE3_H
#define AFFICHAGE3_H
#include "grman.h"
#include <iostream>
#include <stack>
#include "Sommet.h"
#include "widget.h"


class Sommet;///pour qu'elle puisse avoir acces aux donnees de la classe sommet

class Affichage3
{
    friend class Sommet;

    friend class Arc;

public:

    Affichage3();
    ~Affichage3();
    void update3();
    void add_img(std::string image, int x, int y);

//    protected:

//    private:
    ///Fond de l'interface et Box contenant les sommets du graphe 3
    grman::WidgetBox m_fond3;

    grman::WidgetBox m_f_lion;
    grman::WidgetBox m_f_guepard;
    grman::WidgetBox m_f_babouin;
    grman::WidgetBox m_f_serpent;
    grman::WidgetBox m_f_souris;
    grman::WidgetBox m_f_antilope;
    grman::WidgetBox m_f_zebre;
    grman::WidgetBox m_f_herbe;
    grman::WidgetBox m_f_oiseau;
    grman::WidgetBox m_f_mo;
    grman::WidgetBox m_f_elephant;
    grman::WidgetBox m_f_arbre;
    grman::WidgetBox m_f_girafe;
    grman::WidgetImage m_lion;
    grman::WidgetImage m_guepard;
    grman::WidgetImage m_babouin;
    grman::WidgetImage m_serpent;
    grman::WidgetImage m_souris;
    grman::WidgetImage m_antilope;
    grman::WidgetImage m_zebre;
    grman::WidgetImage m_herbe;
    grman::WidgetImage m_oiseau;
    grman::WidgetImage m_mo;
    grman::WidgetImage m_elephant;
    grman::WidgetImage m_arbre;
    grman::WidgetImage m_girafe;
    grman::WidgetEdge m_arbre_girafe;
    grman::WidgetEdge m_arbre_elephant;
    grman::WidgetEdge m_elephant_oiseau;
    grman::WidgetEdge m_elephant_babouin;
    grman::WidgetEdge m_babouin_mo;
    grman::WidgetEdge m_mo_herbe;
    grman::WidgetEdge m_herbe_zebre;
    grman::WidgetEdge m_herbe_antilope;
    grman::WidgetEdge m_herbe_souris;
    grman::WidgetEdge m_zebre_lion;
    grman::WidgetEdge m_antilope_lion;
    grman::WidgetEdge m_lion_babouin;
    grman::WidgetEdge m_guepard_babouin;
    grman::WidgetEdge m_souris_serpent;
    grman::WidgetEdge m_serpent_babouin;
    grman::WidgetEdge m_girafe_lion;
    grman::WidgetEdge m_oiseau_mo;
    grman::WidgetText m_nom_lion;
    grman::WidgetText m_nom_guepard;
    grman::WidgetText m_nom_babouin;
    grman::WidgetText m_nom_serpent;
    grman::WidgetText m_nom_souris;
    grman::WidgetText m_nom_antilope;
    grman::WidgetText m_nom_zebre;
    grman::WidgetText m_nom_herbe;
    grman::WidgetText m_nom_oiseau;
    grman::WidgetText m_nom_mo;
    grman::WidgetText m_nom_elephant;
    grman::WidgetText m_nom_arbre;
    grman::WidgetText m_nom_girafe;
    grman::WidgetVSlider m_pop_lion;
    grman::WidgetVSlider m_pop_guepard;
    grman::WidgetVSlider m_pop_babouin;
    grman::WidgetVSlider m_pop_serpent;
    grman::WidgetVSlider m_pop_souris;
    grman::WidgetVSlider m_pop_antilope;
    grman::WidgetVSlider m_pop_zebre;
    grman::WidgetVSlider m_pop_herbe;
    grman::WidgetVSlider m_pop_oiseau;
    grman::WidgetVSlider m_pop_mo;
    grman::WidgetVSlider m_pop_elephant;
    grman::WidgetVSlider m_pop_arbre;
    grman::WidgetVSlider m_pop_girafe;
    grman::WidgetText m_arbre_giraf;
    grman::WidgetText m_arbre_elephan;
    grman::WidgetText m_elephan_oiseau;
    grman::WidgetText m_elephan_babouin;
    grman::WidgetText m_babou_mo;
    grman::WidgetText m_mo_herb;
    grman::WidgetText m_herb_zebre;
    grman::WidgetText m_herb_antilope;
    grman::WidgetText m_herb_souris;
    grman::WidgetText m_zebre_lio;
    grman::WidgetText m_antilope_lio;
    grman::WidgetText m_lio_babouin;
    grman::WidgetText m_guepar_babouin;
    grman::WidgetText m_souris_serpen;
    grman::WidgetText m_serpen_babouin;
    grman::WidgetText m_giraf_lio;
    grman::WidgetText m_oisea_mo;



};

#endif // AFFICHAGE3_H
