#include "Sommet.h"
#include <float.h>
#include <stdio.h>

/***************************************************
                    SOMMET
****************************************************/


Sommet::Sommet(std::string animal)
{
    std::cout << "DEBUG nom_fichier: " << animal << std::endl;
    std::ifstream info_sommet(animal.c_str(),std::ios::in);

    std::string nom_animal, tmp="", t="true";
    /*double population_t; //double m_population_tpost;
    bool existant;
    int nb_pred;
    float coef_pred1, coef_pred2, r;*/
    std::vector<std::string> tab;

    if(info_sommet)
    {
        std::string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
        getline(info_sommet, contenu);  // on met dans "contenu" la ligne
        //std::cout << "=> " << contenu << ", "<< contenu.length() << std::endl;  // on affiche la ligne

        for( int i=0; i<contenu.length();i++)
        {
            //std::cout << "I: " << i << " " << contenu[i] << std::endl;
            if(i == contenu.length()-1)
            {
                tmp += contenu[i];
                tab.push_back(tmp);
                //std::cout << "tmp= " << tmp << std::endl;
                tmp = ""; //RAZ de la variable tempon
            }
            if(contenu[i] == ' ')
            {
                //std::cout << "oui" << std::endl;
                tab.push_back(tmp);
                //std::cout << "tmp= " << tmp << std::endl;
                tmp = ""; //RAZ de la variable tempon
            }
            else
            {
                //std::cout << "non" << std::endl;
                tmp += contenu[i];
            }

        }

        //std::cout<< "Size tab: " << tab.size() << std::endl;

        for( int i=0; i<tab.size(); i++)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;

        info_sommet.close();

        m_nom=tab[0];
        m_population_t= ::atof(tab[1].c_str()); //string to float/double
        m_existant = (tab[2] == t) ? true : false; // ternary operation
        m_nb_predateur= ::atoi(tab[3].c_str());
        m_coef_predateur1= ::atof(tab[4].c_str()); //string to float/double;
        m_coef_predateur2= ::atof(tab[5].c_str()); //string to float/double
        m_r= ::atof(tab[6].c_str()); //string to float/double

    }
    else
        std::cout<<"Impossible d'ouvrir le fichier"<<std::endl;


}

void Sommet::augmentation_naturL_pop()
{
    float pop; ///Creation des varaibles tempo
    float r;
    double pop_fin;
    float pop_add;
    double m_popul_t;

    m_popul_t=m_population_t;  ///Recupere les variables et on les met au bon type
    pop=(float)m_popul_t;
    r=m_r;

    if (pop<0)
    {
        set_population_t(0);   ///Animal est mort on set donc sa population a 0
    }
    else
    {
    pop_add=pop*r;              ///Calcul de la nouvelle population
    pop_fin=(double)pop_add;
    set_population_t(pop_fin);               ///On stock la nouvelle population dans l'animal en question
    }
}

void Sommet::diminution_naturL_pop1(Sommet* predateur)    ///Diminution pour les animaux avec 1 seul prédateur
{
    double pop_predateur;
    float coef_predateur;
    double pop_animal;

    pop_predateur=(predateur->get_population_t());
    coef_predateur=(predateur->get_coef_predateur1());
    pop_animal=m_population_t;
    if(pop_animal<0)
    {
        set_population_t(0);
    }
    else
    {
        if(pop_predateur>0)
        {
            pop_animal=pop_animal-(coef_predateur*pop_predateur);
            m_population_t=pop_animal;
        }

    }


}

void Sommet::diminution_naturL_pop2(Sommet* predateur, Sommet* predateur2)   ///Diminution pour 2 predateurs
{
    double pop_predateur;
    float coef_predateur;
    double pop_predateur2;
    float coef_predateur2;
    double pop_animal;

    pop_predateur=(predateur->get_population_t());
    coef_predateur=(predateur->get_coef_predateur1());
    pop_predateur2=(predateur2->get_population_t());
    coef_predateur2=(predateur2->get_coef_predateur2());
    pop_animal=m_population_t;

    if (pop_animal<0)
    {
        set_population_t(0);
    }
    else
    {
        if ((pop_predateur2>0) && (pop_predateur>0))   ///Si les deux predateur sont vivants
        {
            pop_animal=pop_animal-(coef_predateur*pop_predateur+coef_predateur2*pop_predateur2);
            set_population_t(pop_animal);
        }
        else if ((pop_predateur2<=0) && (pop_predateur>0))   ///si predateur vivant et predateur 2 mort
        {
            pop_animal=pop_animal-(coef_predateur2*pop_predateur2);
            set_population_t(pop_animal);
        }
        else if ((pop_predateur<=0) && (pop_predateur2>0))    ///Si predateur2 vivant et predateur mort
        {
            pop_animal=pop_animal-(coef_predateur2*pop_predateur2);
            set_population_t(pop_animal);
        }
    }

}

void Sommet::verif_population(Sommet* predateur)        ///Verifie l'état existant des animaux en fonction de leur population
{
    double pop;
    float coef_pred_asso;

    pop=m_population_t;
    coef_pred_asso=(predateur->get_coef_predateur1());

    if (pop<=0)               ///Si l'animal est mort
    {
        set_existant(false);
        std::cout<<m_nom<<" a disparu du monde  "/*<<m_population_t*/<<std::endl;
        predateur->set_coef_pre1(0);
        //predateur->set_coef_pre2(coef_pred2+coef_pred_asso);
    }
    else
    {
        std::cout<<m_nom<<" est toujours existant avec un population de  : "<<m_population_t<<std::endl;
    }

}

void Sommet::verif_population2(Sommet* predateur, Sommet* predateur2)       ///Idem pour 2 predateurs
{
    std::string nom;
    double pop;
    float coef_pred_asso;
    float coef_pred2;

    coef_pred_asso=(predateur->get_coef_predateur1());
    coef_pred2=(predateur->get_coef_predateur2());
    pop=m_population_t;
    if (predateur->get_nom()=="pingouin")
    {

        if (pop<=0)             ///si animal mort
        {
            set_existant(false);
            std::cout<<m_nom<<" a disparu du monde  "/*<<m_population_t*/<<std::endl;
            predateur->set_coef_pre2(0);
            predateur->set_coef_pre1(coef_pred2+coef_pred_asso);
        }

            std::cout<<m_nom<<" est toujours existant avec une population de :  "<<m_population_t<<std::endl;
    }
    else
    {
        if (pop<=0)    ///si animal est mort
        {
            set_existant(false);
            std::cout<<m_nom<<" a disparu du monde "/*<<m_population_t*/<<std::endl;
            predateur->set_coef_pre1(0);
            predateur->set_coef_pre2(coef_pred2+coef_pred_asso);
        }
        //else
            std::cout<<m_nom<<" est toujours existant avec une population de :  "<<m_population_t<<std::endl;
    }

}

void Sommet::verif_pop_proie(Sommet* proie)     ///Verifie que ses sources de nourriture existe encore
{
    double pop_proie;
    pop_proie=proie->get_population_t();

    if(pop_proie<=0)
    {
        set_existant(false);
        set_population_t(0);
        std::cout<<m_nom<<" a disparu car sa source de nourriture : "<<proie->get_nom()<<" a disparu "<<std::endl;
        system("pause");
    }

}

void Sommet::verif_pop_proie2(Sommet* proie1, Sommet* proie2)       ///Verifie pour 2 type de proie possible
{
    double pop_proie1;
    double pop_proie2;

    pop_proie1=proie1->get_population_t();
    pop_proie2=proie2->get_population_t();

    if ((pop_proie2<=0) && (pop_proie1<=0))
    {
        set_existant(false);
        set_population_t(0);
        std::cout<<m_nom<<" a disparu car ses sources de nourriture :"<<proie1->get_nom()<<" et "<<proie2->get_nom()<<" ont disparu. "<<std::endl;
        system("pause");
    }
    else if ((pop_proie2<=0) && (pop_proie1>0))
    {
        std::cout<<"Attention, "<<m_nom<<" n'a plus qu'une seule proie possible : "<<proie1->get_nom()<<std::endl;
    }
    else if((pop_proie1<=0) && (pop_proie2>0))
    {
        std::cout<<"Attention, "<<m_nom<<" n'a plus qu'une seule proie possible : "<<proie2->get_nom()<<std::endl;
    }


}

void Sommet::affichage_etat()
{
    bool etat;
    etat=m_existant;
    if (etat==true)
    {
        std::cout<<m_nom<<" est toujours en vie avec une pop de : "<<m_population_t<<std::endl;
    }
    else
    {
        std::cout<<m_nom<<" a disparu pop : "<<m_population_t<<std::endl;
    }
}
Sommet::~Sommet()
{
    //dtor
}

void Sommet::sauvSommet(std::string nomUtilisateur)
{
    std::string nomFichier = nomUtilisateur + m_nom +".txt";  ///nomUtilisateurorque.txt

    std::ofstream outfile (nomFichier);

    outfile << m_nom <<" "<<m_population_t <<" "<<m_existant << " "<< m_nb_predateur <<" "<<m_coef_predateur1<<" "<<m_coef_predateur2<<" "<<m_r << std::endl;

    outfile.close();

}


