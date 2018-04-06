#ifndef AFFICHAGE2_H
#define AFFICHAGE2_H
#include "grman.h"
#include <iostream>
#include <stack>
#include "Sommet.h"
#include "widget.h"

class Sommet;///pour qu'elle puisse avoir acces aux donnees de la classe sommet

class Affichage2
{
    friend class Sommet;

    friend class Arc;

public:

    Affichage2();
    ~Affichage2();
    void update2();
    void add_img(std::string image, int x, int y);

//    protected:

//    private:
    ///Fond de l'interface et Box contenant les sommets du graphe 2
    grman::WidgetBox m_fond2;
    grman::WidgetBox m_f_requin;
    grman::WidgetBox m_f_thon;
    grman::WidgetBox m_f_phoque;
    grman::WidgetBox m_f_corail;
    grman::WidgetBox m_f_poisson;
    grman::WidgetBox m_f_baleine;
    grman::WidgetBox m_f_plancton;

    ///Image des sommets
    grman::WidgetImage m_requin;
    grman::WidgetImage m_thon;
    grman::WidgetImage m_phoque;
    grman::WidgetImage m_corail;
    grman::WidgetImage m_poisson;
    grman::WidgetImage m_baleine;
    grman::WidgetImage m_plancton;



    /// Construction des Arcs entre les sommets, ils seront tous orient�s vers leur(s) "proie(s)"

    grman::WidgetEdge m_corail_plancton;
    grman::WidgetEdge m_corail_poisson;
    grman::WidgetEdge m_poisson_thon;
    grman::WidgetEdge m_poisson_requin;
    grman::WidgetEdge m_poisson_baleine;
    grman::WidgetEdge m_thon_requin;
    grman::WidgetEdge m_thon_phoque;
    grman::WidgetEdge m_plancton_baleine;
    grman::WidgetEdge m_baleine_corail;
    grman::WidgetEdge m_requin_corail;
    grman::WidgetEdge m_phoque_corail;

    ///Diif�rents noms sommets

    grman::WidgetText m_nom_thon;
    grman::WidgetText m_nom_phoque;
    grman::WidgetText m_nom_requin;
    grman::WidgetText m_nom_poisson;
    grman::WidgetText m_nom_baleine;
    grman::WidgetText m_nom_plancton;
    grman::WidgetText m_nom_corail;

    ///VSlider de la gestion de la population de chaque sommet

    grman::WidgetVSlider m_pop_thon;
    grman::WidgetVSlider m_pop_phoque;
    grman::WidgetVSlider m_pop_requin;
    grman::WidgetVSlider m_pop_poisson;
    grman::WidgetVSlider m_pop_baleine;
    grman::WidgetVSlider m_pop_plancton;
    grman::WidgetVSlider m_pop_corail;

    ///Affichage des valeurs de coef

    grman::WidgetText m_corail_planct;
    grman::WidgetText m_corail_poiss;
    grman::WidgetText m_poisson_tho;
    grman::WidgetText m_poisson_requ;
    grman::WidgetText m_poisson_bale;
    grman::WidgetText m_thon_req;
    grman::WidgetText m_thon_phoq;
    grman::WidgetText m_plancton_bale;
    grman::WidgetText m_baleine_cora;
    grman::WidgetText m_requin_cora;
    grman::WidgetText m_phoque_cora;



};

#endif // AFFICHAGE2_H
