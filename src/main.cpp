#include "../grman/grman.h"
#include <iostream>
#include "grman.h"
#include "graph.h"
#include "Affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "Sommet.h"

int main()
{
    std::cout<<"coco"<<std::endl;
    grman::set_pictures_path("pics");
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger
    std::cout<<"cocCCo"<<std::endl;
    Sommet orque;
    Sommet phoque;
    Sommet pingouin;
    Sommet krill;
    Sommet poisson;
    Sommet mo;

    Affichage affich;



    std::cout<<"c"<<std::endl;
    while ( !key[KEY_ESC] )
    {
        //pingouin.set_population_t(m_pop_ping.get_value());
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        affich.update();


        ///if(add image){affich.add_img()}
        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
    /*/// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");
    */
    /// Un exemple de graphe
   // Graph graphJade;
    //g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    /*while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();
    */

    return 0;
}
END_OF_MAIN();


