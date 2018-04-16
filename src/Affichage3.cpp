#include "Affichage3.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Affichage3::Affichage3()
{
    ///Construction du fond blanc
    m_fond3.set_dim(1000,750);
    m_fond3.set_bg_color(BLANC);
    m_fond3.set_moveable();

    ///Construction des sommets (Box mobiles)

    m_fond3.add_child(m_f_lion);
    m_f_lion.set_frame(630, 0, 170, 170);
    m_f_lion.set_bg_color(BLANC);
    m_f_lion.set_moveable();
    m_f_lion.add_child( m_lion );
    m_lion.set_pic_name("lion.bmp");

    m_fond3.add_child( m_f_guepard );
    m_f_guepard.set_frame(110, 0, 170,170);
    m_f_guepard.set_bg_color(BLANC);
    m_f_guepard.set_moveable();
    m_f_guepard.add_child(m_guepard);
    m_guepard.set_pic_name("guepard.bmp");

    m_fond3.add_child( m_f_babouin );
    m_f_babouin.set_frame(300, 0, 170, 170);
    m_f_babouin.set_bg_color(BLANC);
    m_f_babouin.set_moveable();
    m_f_babouin.add_child(m_babouin);
    m_babouin.set_pic_name("babouin.bmp");

    m_fond3.add_child( m_f_serpent );
    m_f_serpent.set_frame(110, 180, 170,170);
    m_f_serpent.set_bg_color(BLANC);
    m_f_serpent.set_moveable();
    m_f_serpent.add_child(m_serpent);
    m_serpent.set_pic_name("serpent.bmp");

    m_fond3.add_child( m_f_souris );
    m_f_souris.set_frame(110, 450, 170,170);
    m_f_souris.set_bg_color(BLANC);
    m_f_souris.set_moveable();
    m_f_souris.add_child(m_souris);
    m_souris.set_pic_name("souris.bmp");

    m_fond3.add_child( m_f_antilope );
    m_f_antilope.set_frame(830, 550, 170, 170);
    m_f_antilope.set_bg_color(BLANC);
    m_f_antilope.set_moveable();
    m_f_antilope.add_child(m_antilope);
    m_antilope.set_pic_name("antilope.bmp");

    m_fond3.add_child( m_f_zebre );
    m_f_zebre.set_frame(630, 360, 170, 170);
    m_f_zebre.set_bg_color(BLANC);
    m_f_zebre.set_moveable();
    m_f_zebre.add_child(m_zebre);
    m_zebre.set_pic_name("zebre.bmp");

    m_fond3.add_child( m_f_herbe );
    m_f_herbe.set_frame(250, 130, 170, 170);
    m_f_herbe.set_bg_color(BLANC);
    m_f_herbe.set_moveable();
    m_f_herbe.add_child(m_herbe);
    m_herbe.set_pic_name("herbe.bmp");

    m_fond3.add_child( m_f_mo );
    m_f_mo.set_frame(250, 130, 170, 170);
    m_f_mo.set_bg_color(BLANC);
    m_f_mo.set_moveable();
    m_f_mo.add_child(m_mo);
    m_mo.set_pic_name("mo.bmp");

    m_fond3.add_child( m_f_oiseau );
    m_f_oiseau.set_frame(250, 130, 170, 170);
    m_f_oiseau.set_bg_color(BLANC);
    m_f_oiseau.set_moveable();
    m_f_oiseau.add_child(m_oiseau);
    m_oiseau.set_pic_name("oiseau.bmp");

    m_fond3.add_child( m_f_elephant );
    m_f_elephant.set_frame(250, 130, 170, 170);
    m_f_elephant.set_bg_color(BLANC);
    m_f_elephant.set_moveable();
    m_f_elephant.add_child(m_elephant);
    m_elephant.set_pic_name("elephant.bmp");

    m_fond3.add_child( m_f_arbre );
    m_f_arbre.set_frame(830, 280, 170, 170);
    m_f_arbre.set_bg_color(BLANC);
    m_f_arbre.set_moveable();
    m_f_arbre.add_child(m_arbre);
    m_arbre.set_pic_name("arbre.bmp");

    m_fond3.add_child( m_f_girafe );
    m_f_girafe.set_frame(830, 0, 170, 170);
    m_f_girafe.set_bg_color(BLANC);
    m_f_girafe.set_moveable();
    m_f_girafe.add_child(m_girafe);
    m_girafe.set_pic_name("girafe.bmp");


    ///Construction des arcs orientés

    m_fond3.add_child( m_arbre_girafe );
    m_arbre_girafe.attach_from(m_f_arbre);
    m_arbre_girafe.attach_to(m_f_girafe);
    m_arbre_girafe.reset_arrow_with_bullet();

    m_fond3.add_child( m_arbre_elephant );
    m_arbre_elephant.attach_from(m_f_arbre);
    m_arbre_elephant.attach_to(m_f_elephant);
    m_arbre_elephant.reset_arrow_with_bullet();

    m_fond3.add_child( m_elephant_babouin );
    m_elephant_babouin.attach_from(m_f_elephant);
    m_elephant_babouin.attach_to(m_f_babouin);
    m_elephant_babouin.reset_arrow_with_bullet();

    m_fond3.add_child( m_elephant_oiseau );
    m_elephant_oiseau.attach_from(m_f_elephant);
    m_elephant_oiseau.attach_to(m_f_oiseau);
    m_elephant_oiseau.reset_arrow_with_bullet();

    m_fond3.add_child( m_babouin_mo );
    m_babouin_mo.attach_from(m_f_babouin);
    m_babouin_mo.attach_to(m_f_mo);
    m_babouin_mo.reset_arrow_with_bullet();

    m_fond3.add_child( m_mo_herbe );
    m_mo_herbe.attach_from(m_f_herbe);
    m_mo_herbe.attach_to(m_f_mo);
    m_mo_herbe.reset_arrow_with_bullet();

    m_fond3.add_child( m_herbe_zebre );
    m_herbe_zebre.attach_from(m_f_herbe);
    m_herbe_zebre.attach_to(m_f_zebre);
    m_herbe_zebre.reset_arrow_with_bullet();

    m_fond3.add_child( m_herbe_antilope);
    m_herbe_antilope.attach_from(m_f_herbe);
    m_herbe_antilope.attach_to(m_f_antilope);
    m_herbe_antilope.reset_arrow_with_bullet();

    m_fond3.add_child( m_herbe_souris);
    m_herbe_souris.attach_from(m_f_herbe);
    m_herbe_souris.attach_to(m_f_souris);
    m_herbe_souris.reset_arrow_with_bullet();

    m_fond3.add_child( m_zebre_lion);
    m_zebre_lion.attach_from(m_f_zebre);
    m_zebre_lion.attach_to(m_f_lion);
    m_zebre_lion.reset_arrow_with_bullet();

    m_fond3.add_child( m_antilope_lion);
    m_antilope_lion.attach_from(m_f_antilope);
    m_antilope_lion.attach_to(m_f_zebre);
    m_antilope_lion.reset_arrow_with_bullet();

    m_fond3.add_child( m_lion_babouin );
    m_lion_babouin.attach_from(m_f_lion);
    m_lion_babouin.attach_to(m_f_babouin);
    m_lion_babouin.reset_arrow_with_bullet();

    m_fond3.add_child( m_guepard_babouin );
    m_guepard_babouin.attach_from(m_f_guepard);
    m_guepard_babouin.attach_to(m_f_babouin);
    m_guepard_babouin.reset_arrow_with_bullet();

    m_fond3.add_child( m_souris_serpent );
    m_souris_serpent.attach_from(m_f_souris);
    m_souris_serpent.attach_to(m_f_serpent);
    m_souris_serpent.reset_arrow_with_bullet();

    m_fond3.add_child( m_serpent_babouin );
    m_serpent_babouin.attach_from(m_f_serpent);
    m_serpent_babouin.attach_to(m_f_babouin);
    m_serpent_babouin.reset_arrow_with_bullet();

    m_fond3.add_child( m_girafe_lion );
    m_girafe_lion.attach_from(m_f_girafe);
    m_girafe_lion.attach_to(m_f_lion);
    m_girafe_lion.reset_arrow_with_bullet();

    m_fond3.add_child( m_oiseau_mo );
    m_oiseau_mo.attach_from(m_f_oiseau);
    m_oiseau_mo.attach_to(m_f_mo);
    m_oiseau_mo.reset_arrow_with_bullet();



    ///Information écrite
    ///Nom des sommets
    m_f_lion.add_child( m_nom_lion );
    m_nom_lion.set_message("LION");
    m_nom_lion.set_gravity_y(grman::GravityY::Down );

    m_f_guepard.add_child( m_nom_guepard );
    m_nom_guepard.set_message("GUEPARD");
    m_nom_guepard.set_gravity_y(grman::GravityY::Down );

    m_f_babouin.add_child( m_nom_babouin );
    m_nom_babouin.set_message("BABOUIN");
    m_nom_babouin.set_gravity_y(grman::GravityY::Down );

    m_f_serpent.add_child( m_nom_serpent );
    m_nom_serpent.set_message("SERPENT");
    m_nom_serpent.set_gravity_y(grman::GravityY::Down );

    m_f_souris.add_child( m_nom_souris );
    m_nom_souris.set_message("SOURIS");
    m_nom_souris.set_gravity_y(grman::GravityY::Down );

    m_f_antilope.add_child( m_nom_antilope );
    m_nom_antilope.set_message("ANTILOPE");
    m_nom_antilope.set_gravity_y(grman::GravityY::Down );

    m_f_zebre.add_child( m_nom_zebre );
    m_nom_zebre.set_message("ZEBRE");
    m_nom_zebre.set_gravity_y(grman::GravityY::Down );

    m_f_herbe.add_child( m_nom_herbe );
    m_nom_herbe.set_message("HERBE");
    m_nom_herbe.set_gravity_y(grman::GravityY::Down );

    m_f_oiseau.add_child( m_nom_oiseau );
    m_nom_oiseau.set_message("OISEAU");
    m_nom_oiseau.set_gravity_y(grman::GravityY::Down );

    m_f_mo.add_child( m_nom_mo );
    m_nom_mo.set_message("MAT; ORGANIQUE");
    m_nom_mo.set_gravity_y(grman::GravityY::Down );

    m_f_elephant.add_child( m_nom_elephant );
    m_nom_elephant.set_message("ELEPHANT");
    m_nom_elephant.set_gravity_y(grman::GravityY::Down );

    m_f_arbre.add_child( m_nom_arbre );
    m_nom_arbre.set_message("ARBRE");
    m_nom_arbre.set_gravity_y(grman::GravityY::Down );

    m_f_girafe.add_child( m_nom_girafe );
    m_nom_girafe.set_message("GIRAFE");
    m_nom_girafe.set_gravity_y(grman::GravityY::Down );



    /// Dans ce sous cadre on ajoute 2 ascenseurs verticaux
    m_f_lion.add_child( m_pop_lion );
    m_pop_lion.set_gravity_x(grman::GravityX::Left);
    m_pop_lion.set_bg_color(BLANC);
    m_pop_lion.set_range(1, 20,true);
    m_pop_lion.set_frame(2,10,15,70);
    m_pop_lion.set_value(10);
    m_pop_lion.interact_focus();

    m_f_guepard.add_child( m_pop_guepard );
    m_pop_guepard.set_gravity_x(grman::GravityX::Left);
    m_pop_guepard.set_bg_color(BLANC);
    m_pop_guepard.set_range(1, 20,true);
    m_pop_guepard.set_frame(2,10,15,70);
    m_pop_guepard.set_value(10);
    m_pop_guepard.interact_focus();

    m_f_babouin.add_child( m_pop_babouin );
    m_pop_babouin.set_gravity_x(grman::GravityX::Left);
    m_pop_babouin.set_bg_color(BLANC);
    m_pop_babouin.set_range(1, 20,true);
    m_pop_babouin.set_frame(2,10,15,70);
    m_pop_babouin.set_value(10);
    m_pop_babouin.interact_focus();

    m_f_serpent.add_child( m_pop_serpent );
    m_pop_serpent.set_gravity_x(grman::GravityX::Left);
    m_pop_serpent.set_bg_color(BLANC);
    m_pop_serpent.set_range(1, 20,true);
    m_pop_serpent.set_frame(2,10,15,70);
    m_pop_serpent.set_value(10);
    m_pop_serpent.interact_focus();

    m_f_souris.add_child( m_pop_souris );
    m_pop_souris.set_gravity_x(grman::GravityX::Left);
    m_pop_souris.set_bg_color(BLANC);
    m_pop_souris.set_range(1, 20,true);
    m_pop_souris.set_frame(2,10,15,70);
    m_pop_souris.set_value(10);
    m_pop_souris.interact_focus();

    m_f_antilope.add_child( m_pop_antilope );
    m_pop_antilope.set_gravity_x(grman::GravityX::Left);
    m_pop_antilope.set_bg_color(BLANC);
    m_pop_antilope.set_range(1, 20,true);
    m_pop_antilope.set_frame(2,10,15,70);
    m_pop_antilope.set_value(10);
    m_pop_antilope.interact_focus();

    m_f_zebre.add_child( m_pop_zebre );
    m_pop_zebre.set_gravity_x(grman::GravityX::Left);
    m_pop_zebre.set_bg_color(BLANC);
    m_pop_zebre.set_range(1, 20,true);
    m_pop_zebre.set_frame(2,10,15,70);
    m_pop_zebre.set_value(10);
    m_pop_zebre.interact_focus();

    m_f_herbe.add_child( m_pop_herbe );
    m_pop_herbe.set_gravity_x(grman::GravityX::Left);
    m_pop_herbe.set_bg_color(BLANC);
    m_pop_herbe.set_range(1, 20,true);
    m_pop_herbe.set_frame(2,10,15,70);
    m_pop_herbe.set_value(10);
    m_pop_herbe.interact_focus();

    m_f_oiseau.add_child( m_pop_oiseau );
    m_pop_oiseau.set_gravity_x(grman::GravityX::Left);
    m_pop_oiseau.set_bg_color(BLANC);
    m_pop_oiseau.set_range(1, 20,true);
    m_pop_oiseau.set_frame(2,10,15,70);
    m_pop_oiseau.set_value(10);
    m_pop_oiseau.interact_focus();

    m_f_mo.add_child( m_pop_mo );
    m_pop_mo.set_gravity_x(grman::GravityX::Left);
    m_pop_mo.set_bg_color(BLANC);
    m_pop_mo.set_range(1, 20,true);
    m_pop_mo.set_frame(2,10,15,70);
    m_pop_mo.set_value(10);
    m_pop_mo.interact_focus();

    m_f_elephant.add_child( m_pop_elephant );
    m_pop_elephant.set_gravity_x(grman::GravityX::Left);
    m_pop_elephant.set_bg_color(BLANC);
    m_pop_elephant.set_range(1, 20,true);
    m_pop_elephant.set_frame(2,10,15,70);
    m_pop_elephant.set_value(10);
    m_pop_elephant.interact_focus();

    m_f_arbre.add_child( m_pop_arbre );
    m_pop_arbre.set_gravity_x(grman::GravityX::Left);
    m_pop_arbre.set_bg_color(BLANC);
    m_pop_arbre.set_frame(2,10,15,70);
    m_pop_arbre.set_value(10);
    m_pop_arbre.interact_focus();

    m_f_girafe.add_child( m_pop_girafe );
    m_pop_girafe.set_gravity_x(grman::GravityX::Left);
    m_pop_girafe.set_bg_color(BLANC);
    m_pop_girafe.set_range(1, 20,true);
    m_pop_girafe.set_frame(2,10,15,70);
    m_pop_girafe.set_value(10);
    m_pop_girafe.interact_focus();

}

Affichage3::~Affichage3()
{
    //dtor
}


void Affichage3::update3()
{

    /// Si tous les widgets dépendants de l'objet sont dans une top box
    /// alors ce seul appel suffit (la propagation d'updates se fait ensuite automatiquement)
    m_fond3.update();




}
