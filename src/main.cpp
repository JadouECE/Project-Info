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

int main()
{
    std::cout<<"coco"<<std::endl;
    grman::set_pictures_path("pics");
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    std::cout<<"cocCCo"<<std::endl;
    Sommet orque;
    Sommet phoque;
    Sommet pingouin;
    Sommet krill;
    Sommet poisson;
    Sommet mo;

    Arc pho_or( &phoque , &orque , 1.2);
    Arc ping_pho (&pingouin , & phoque ,1.1);
    Arc ping_or (&pingouin ,&phoque , 1.3);
    Arc poi_ping (&poisson ,&pingouin ,1.24);
    Arc kri_ping (&krill , &pingouin, 1.12);
    Arc kri_poi (&krill, &poisson, 1.13);
    Arc mo_kri (&mo , &krill , 1.1);
    Arc or_mo (&orque , &mo, 1.12);

    Affichage affich;
    Affichage2 affich2;
    Menu M;

    while( !M.m_bouton1.clicked() ||  !M.m_bouton2.clicked() || !M.m_bouton3.clicked() )
    {

        M.update();


        ///if(add image){affich.add_img()}
        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

    if (M.m_bouton1.clicked())
    {
        while (!key[KEY_ESC])
        {
            affich.update();

        pingouin.set_population_t(affich.m_pop_ping.get_value());
        phoque.set_population_t(affich.m_pop_pho.get_value());
        orque.set_population_t(affich.m_pop_orque.get_value());
        krill.set_population_t(affich.m_pop_krill.get_value());
        mo.set_population_t(affich.m_pop_krill.get_value());
        poisson.set_population_t(affich.m_pop_poisson.get_value());



            grman::mettre_a_jour();
        }

    }

    if (M.m_bouton2.clicked())
    {
        while (!key[KEY_ESC])
        {
            affich2.update2();



            grman::mettre_a_jour();
        }

    }

    }


    /*/// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");
    */
    /// Un exemple de graphe
   // Graph graphJade;
    //g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    /*while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();
    */
    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


