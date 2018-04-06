#ifndef SOMMET_H
#define SOMMET_H
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "Affichage.h"
/***************************************************
                    SOMMET
****************************************************/

/* class VertexInterface
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Vertex;
    friend class EdgeInterface;
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        // La boite qui contient toute l'interface d'un sommet
        grman::WidgetBox m_top_box;

        // Un slider de visualisation/modification de la valeur du sommet
        grman::WidgetVSlider m_slider_value;

        // Un label de visualisation de la valeur du sommet
        grman::WidgetText m_label_value;

        // Une image de "remplissage"
        grman::WidgetImage m_img;

        // Un label indiquant l'index du sommet
        grman::WidgetText m_label_idx;

        // Une boite pour le label précédent
        grman::WidgetText m_box_label_idx;

    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        VertexInterface(int idx, int x, int y, std::string pic_name="", int pic_idx=0);
};
*/
class Affichage;
class Sommet
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    //friend class SommetInterface;
    friend class Arc;
    //friend class ArcInterface;

    private :

        //std::string m_nom;
        /// population aux moments t et t+1 de l'espèce
        double m_population_t;
        double m_population_tpost;
        bool m_existant;
        int m_nb_proie;
        float m_coef_proie1;
        float m_coef_proie2;
        float m_r;
        //int m_index;
        /// liste des arcs arrivant au sommet : proies
        //std::vector<Arc*> m_proie;
        /// liste des arcs partant du sommet : prédateur
        //std::vector<Arc*> m_predateur;

        /// Regulation population (coefficient d'augmentation population
        //int m_regulation;
        /// Sommet prédateur qui va influer sur la population de notre espece
        //Sommet* m_predateur;

       /* /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<SommetInterface> m_interface = nullptr;

        // Docu shared_ptr : https://msdn.microsoft.com/fr-fr/library/hh279669.aspx
        // La ligne précédente est en gros équivalent à la ligne suivante :
        // SommetInterface * m_interface = nullptr;
        */

    public:

        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        //Sommet (std::string s_nom , std::string s_type , int s_index , int s_population_t ,int s_population_tpost , float s_regulation , std::string s_nom_predateur);
        Sommet();
        ~Sommet();
        double augmentation_naturelle_pop();
        void set_population_t(double pop) {m_population_t=pop;}
        double get_population_t() {return m_population_t;}
        float get_r() {return m_r;}
        /// Vertex étant géré par Graph ce sera la méthode update de graph qui appellera
        /// le pre_update et post_update de Vertex (pas directement la boucle de jeu)
        /// Voir l'implémentation Graph::update dans le .cpp
       // void pre_update();
        //void post_update();
};

#endif // SOMMET_H
