#include "../grman/grman.h"
#include <iostream>
#include "grman.h"
#include "graph.h"
#include "Affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "Sommet.h"
#include "widget.h"
#include "Menu.h"
#include "Affichage2.h"
#include "Affichage3.h"
#include <unistd.h>





int main()
{


    grman::set_pictures_path("pics");
    grman::init();

    /// Construction des différentes varibales
    Sommet orque ("orque.txt");
    Sommet phoque ("phoque.txt");
    Sommet pingouin ("pingouin.txt");
    Sommet poisson ("poisson.txt");
    Sommet krill ("krill.txt");
    Sommet mo ("mo.txt");

    Arc pho_or( &phoque, &orque, 1.2);
    Arc ping_pho (&pingouin, & phoque,1.1);
    Arc ping_or (&pingouin,&phoque, 1.3);
    Arc poi_ping (&poisson,&pingouin,1.24);
    Arc kri_ping (&krill, &pingouin, 1.12);
    Arc kri_poi (&krill, &poisson, 1.13);
    Arc mo_kri (&mo, &krill, 1.1);
    Arc or_mo (&orque, &mo, 1.12);

    Affichage affich;
    Affichage2 affich2;
    Affichage3 affich3;
    Menu M;



    while( !M.m_bouton1.clicked() ||  !M.m_bouton2.clicked() || !M.m_bouton3.clicked() )   ///Tant qu'aucun graphe n'est choisi
    {

        M.update();
        grman::mettre_a_jour();

        if (M.m_bouton1.clicked())                  ///Entre dans le graphe 1
        {
            while (!key[KEY_ESC])               ///On crée une sortie du graphe avec la touche Escape
            {
                affich.update();

                pingouin.set_population_t(affich.m_pop_ping.get_value());           ///On regule les populations en fonction des populations rentrées
                phoque.set_population_t(affich.m_pop_pho.get_value());              ///avec les sliders
                orque.set_population_t(affich.m_pop_orque.get_value());
                krill.set_population_t(affich.m_pop_krill.get_value());
                mo.set_population_t(affich.m_pop_krill.get_value());
                poisson.set_population_t(affich.m_pop_poisson.get_value());
                if (affich.m_play.clicked())    ///Lancement tant qu'on ne quitte pas avec q la variation
                {
                    int i=1;
                    while (!key[KEY_Q])   ///On decide de lancer la variation en cliquant sur le bouton play
                    {
                        std::cout<<"Pop depart orque : "<<orque.get_population_t()<<std::endl;          ///On affiche les populations de depart
                        std::cout<<"Pop depart phoque : "<<phoque.get_population_t()<<std::endl;
                        std::cout<<"Pop depart poisson : "<<poisson.get_population_t()<<std::endl;
                        std::cout<<"Pop depart pingouin : "<<pingouin.get_population_t()<<std::endl;
                        std::cout<<"Pop depart krill: "<<krill.get_population_t()<<std::endl;
                        std::cout<<"Pop depart mo : "<<mo.get_population_t()<<std::endl;

                        system("pause");

                        ///Augmentation naturelle de la population
                        orque.augmentation_naturL_pop();
                        phoque.augmentation_naturL_pop();
                        pingouin.augmentation_naturL_pop();
                        poisson.augmentation_naturL_pop();
                        krill.augmentation_naturL_pop();
                        mo.augmentation_naturL_pop();

                        std::cout<<"Pop apres agm naturelle orque : "<<orque.get_population_t()<<std::endl;          ///On affiche les populations apres augmentation naturelle
                        std::cout<<"Pop apres agm naturelle phoque : "<<phoque.get_population_t()<<std::endl;
                        std::cout<<"Pop apres agm naturelle poisson : "<<poisson.get_population_t()<<std::endl;
                        std::cout<<"Pop apres agm naturelle pingouin : "<<pingouin.get_population_t()<<std::endl;
                        std::cout<<"Pop apres agm naturelle krill: "<<krill.get_population_t()<<std::endl;
                        //std::cout<<"Pop apres agm naturelle mo : "<<mo.get_population_t()<<std::endl;

                        ///Diminution par la prédation
                        orque.diminution_naturL_pop1(&mo);   //nan ?
                        mo.diminution_naturL_pop1(&krill);
                        krill.diminution_naturL_pop2(&pingouin,&poisson);
                        poisson.diminution_naturL_pop1(&pingouin);
                        pingouin.diminution_naturL_pop2(&phoque,&orque);
                        phoque.diminution_naturL_pop1(&orque);

                        system("pause");

                        std::cout<<"Pop apres dim naturelle orque : "<<orque.get_population_t()<<std::endl;          ///On affiche les populations apres augmentation naturelle et diminution par predation
                        std::cout<<"Pop apres dim naturelle phoque : "<<phoque.get_population_t()<<std::endl;
                        std::cout<<"Pop apres dim naturelle poisson : "<<poisson.get_population_t()<<std::endl;
                        std::cout<<"Pop apres dim naturelle pingouin : "<<pingouin.get_population_t()<<std::endl;
                        std::cout<<"Pop apres dim naturelle krill: "<<krill.get_population_t()<<std::endl;
                        //std::cout<<"Pop apres dim naturelle mo : "<<mo.get_population_t()<<std::endl;

                        system("pause");

                        orque.verif_population(&mo);       ///On set a 0 les entités mortes et on change les coefficients de predation des predateurs de l'animal mort
                        phoque.verif_population(&orque);
                        pingouin.verif_population2(&phoque,&orque);
                        poisson.verif_population(&pingouin);
                        krill.verif_population2(&pingouin, &poisson);
                        //mo.verif_population(&krill);
                        ///Sauf pour la matiere organique car elle ne meurt pas et se regénère à la mort de tous les animaux

                        phoque.verif_pop_proie(&pingouin);         ///On vérifie les population de la proie (si proie plus existantes avec peu pas survivre)
                        poisson.verif_pop_proie(&krill);

                        //krill.verif_pop_proie(&mo);
                        ///Encore une fois sauf la mo
                        orque.verif_pop_proie2(&phoque,&pingouin);          ///idem pour si 2 proie alors il peut survivre avec l'un des deux

                        pingouin.verif_pop_proie2(&poisson,&krill);

                        //on ne verifie pas le mo car les mo ne meurt pas

                        std::cout<<"fin de la preriode "<<i<<std::endl;


                        i++;
                        system("pause");
                    }
                }
                else if(affich.m_sauvergarder.clicked())
                {
                    std::string nom_utilisateur;
                    std::cout<<"Entrez un nom d'utilisateur"<<std::endl;
                    std::cin>>nom_utilisateur;
                    orque.sauvSommet(nom_utilisateur);
                    phoque.sauvSommet(nom_utilisateur);
                    pingouin.sauvSommet(nom_utilisateur);
                    poisson.sauvSommet(nom_utilisateur);
                    krill.sauvSommet(nom_utilisateur);
                    mo.sauvSommet(nom_utilisateur);

                    std::cout<<"Le fichier est bien sauvegardé"<<std::endl;
                }
                grman::mettre_a_jour();
            }
            // affich.update();



        }







        if (M.m_bouton2.clicked())
        {
            while (!key[KEY_ESC])
            {
                int i=1;
                affich2.update2();



                grman::mettre_a_jour();
                i++;
                //std::cout<<i<<std::endl;
            }

        }

        if (M.m_bouton3.clicked())
        {
            while (!key[KEY_ESC])
            {
                affich3.update3();

                int i=1;

                grman::mettre_a_jour();
                i++;
                //std::cout<<i<<std::endl;
            }

        }
    }

        grman::fermer_allegro();

        return 0;
    }

    END_OF_MAIN();


