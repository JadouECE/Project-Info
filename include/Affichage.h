#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "grman.h"
#include <iostream>
#include <stack>
#include "Sommet.h"

class Sommet;
class Affichage
{
    friend class Sommet;
    friend class Arc;
    public:
        Affichage();
        ~Affichage();
        void update();
        void add_img(std::string image, int x, int y);

    protected:

    private:
        ///Fond de l'interface et Box contenant les sommets
        grman::WidgetBox m_fond;
        grman::WidgetBox m_f_orque;
        grman::WidgetBox m_f_pingouin;
        grman::WidgetBox m_f_phoque;
        grman::WidgetBox m_f_mo;
        grman::WidgetBox m_f_poisson;
        grman::WidgetBox m_f_krill;

        ///Image des sommets
        grman::WidgetImage m_image;
        grman::WidgetImage m_orque;
        grman::WidgetImage m_pingouin;
        grman::WidgetImage m_phoque;
        grman::WidgetImage m_mo;
        grman::WidgetImage m_poisson;
        grman::WidgetImage m_krill;
        grman::WidgetText m_dragme;


        /// Construction des Arcs entre les sommets, ils seront tous orientés vers leur(s) "proie(s)"

    grman::WidgetEdge m_mo_k;
    grman::WidgetEdge m_k_poisson;
    grman::WidgetEdge m_k_ping;
    grman::WidgetEdge m_poisson_ping;
    grman::WidgetEdge m_ping_phoque;
    grman::WidgetEdge m_ping_orque;
    grman::WidgetEdge m_phoque_orque;
    grman::WidgetEdge m_orque_mo;

        ///Diiférents textes

    grman::WidgetText m_nom_orque;
    grman::WidgetText m_nom_phoque;
    grman::WidgetText m_nom_pingouin;
    grman::WidgetText m_nom_poisson;
    grman::WidgetText m_nom_krill;
    grman::WidgetText m_nom_mo;

        ///VSlider de la gestion de la population de chaque sommet

    grman::WidgetVSlider m_pop_orque;
    grman::WidgetVSlider m_pop_pho;
    grman::WidgetVSlider m_pop_ping;
    grman::WidgetVSlider m_pop_poisson;
    grman::WidgetVSlider m_pop_krill;
    grman::WidgetVSlider m_pop_mo;








};

#endif // AFFICHAGE_H
