#ifndef SOMMET_H
#define SOMMET_H
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "Affichage.h"
#include <vector>
#include <map>
#include <fstream>
#include <ios>
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

        std::string m_nom;
        double m_population_t;
        //double m_population_tpost;
        bool m_existant;
        int m_nb_proie;
        float m_coef_proie1;
        float m_coef_proie2;
        int m_nb_predateur;
        float m_coef_predateur1;
        float m_coef_predateur2;
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
        Sommet(std::string nom_fichier);
        ~Sommet();

        ///Modulation de la population
        void augmentation_naturL_pop();
        void diminution_naturL_pop1(Sommet* predateur);
        void diminution_naturL_pop2(Sommet* predateur, Sommet* predateur2);
        ///Verifications
        void verif_population(Sommet* predateur);
        void verif_population2(Sommet* predateur, Sommet* predateur2);
        void verif_pop_proie(Sommet* proie);
        void verif_pop_proie2(Sommet* proie1, Sommet* proie2);
        ///Affichage etat des sommets
        void affichage_etat();
        void sauvSommet(std::string nomUtilisateur);

        ///Getter et Setter
        void set_population_t(double pop) {m_population_t=pop;}
        double get_population_t() {return m_population_t;}
        float get_r() {return m_r;}
        std::string get_nom(){return m_nom;}
        int get_nb_proie(){return m_nb_proie;}
        int get_nb_predateur(){return m_nb_predateur;}
        float get_coef_proie1(){return m_coef_proie1;}
        float get_coef_proie2(){return m_coef_proie2;}
        float get_coef_predateur1(){return m_coef_predateur1;}
        float get_coef_predateur2(){return m_coef_predateur2;}
        float get_m_r(){return m_r;}

        void set_nom(std::string nom){m_nom=nom;}
        void set_existant(bool b){m_existant=b;}
        void set_nb_proie(int nbpr){m_nb_proie=nbpr;}
        void set_nb_pre(int nbpre){m_nb_predateur=nbpre;}
        void set_coef_pro1(float coef){m_coef_proie1=coef;}
        void set_coef_pro2(float coef){m_coef_proie2=coef;}
        void set_coef_pre1(float coef){m_coef_predateur1=coef;}
        void set_coef_pre2(float coef){m_coef_predateur2=coef;}
        void set_r(float r){m_r=r;}

};

#endif // SOMMET_H
