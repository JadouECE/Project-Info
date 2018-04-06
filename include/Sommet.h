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
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Vertex;
    friend class EdgeInterface;
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de d�clarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le param�trer ( voir l'impl�mentation du constructeur dans le .cpp )

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

        // Une boite pour le label pr�c�dent
        grman::WidgetText m_box_label_idx;

    public :

        // Le constructeur met en place les �l�ments de l'interface
        // voir l'impl�mentation dans le .cpp
        VertexInterface(int idx, int x, int y, std::string pic_name="", int pic_idx=0);
};
*/
class Affichage;
class Sommet
{
    // Les (methodes des) classes amies pourront acc�der
    // directement aux attributs (y compris priv�s)
    friend class Graph;
    //friend class SommetInterface;
    friend class Arc;
    //friend class ArcInterface;

    private :

        //std::string m_nom;
        /// population aux moments t et t+1 de l'esp�ce
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
        /// liste des arcs partant du sommet : pr�dateur
        //std::vector<Arc*> m_predateur;

        /// Regulation population (coefficient d'augmentation population
        //int m_regulation;
        /// Sommet pr�dateur qui va influer sur la population de notre espece
        //Sommet* m_predateur;

       /* /// le POINTEUR sur l'interface associ�e, nullptr -> pas d'interface
        std::shared_ptr<SommetInterface> m_interface = nullptr;

        // Docu shared_ptr : https://msdn.microsoft.com/fr-fr/library/hh279669.aspx
        // La ligne pr�c�dente est en gros �quivalent � la ligne suivante :
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
        /// Vertex �tant g�r� par Graph ce sera la m�thode update de graph qui appellera
        /// le pre_update et post_update de Vertex (pas directement la boucle de jeu)
        /// Voir l'impl�mentation Graph::update dans le .cpp
       // void pre_update();
        //void post_update();
};

#endif // SOMMET_H
