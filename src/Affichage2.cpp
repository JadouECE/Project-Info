#include "Affichage2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Affichage2::Affichage2()
{
    ///Construction du fond blanc
    m_fond2.set_dim(1000,750);
    m_fond2.set_bg_color(BLANC);
    m_fond2.set_moveable();

    ///Construction des sommets (Box mobiles)

    m_fond2.add_child(m_f_thon);
    m_f_thon.set_frame(830, 0, 170, 170);
    m_f_thon.set_bg_color(BLANC);
    m_f_thon.set_moveable();
    m_f_thon.add_child( m_thon );
    m_thon.set_pic_name("thon.bmp");

    m_fond2.add_child( m_f_phoque );
    m_f_phoque.set_frame(425, 0, 170,170);
    m_f_phoque.set_bg_color(BLANC);
    m_f_phoque.set_moveable();
    m_f_phoque.add_child(m_phoque);
    m_phoque.set_pic_name("phoque.bmp");

    m_fond2.add_child( m_f_poisson );
    m_f_poisson.set_frame(830, 550, 170, 170);
    m_f_poisson.set_bg_color(BLANC);
    m_f_poisson.set_moveable();
    m_f_poisson.add_child(m_poisson);
    m_poisson.set_pic_name("poisson.bmp");

    m_fond2.add_child( m_f_requin );
    m_f_requin.set_frame(690, 225, 170,170);
    m_f_requin.set_bg_color(BLANC);
    m_f_requin.set_moveable();
    m_f_requin.add_child(m_requin);
    m_requin.set_pic_name("requin.bmp");

    m_fond2.add_child( m_f_baleine );
    m_f_baleine.set_frame(140, 550, 170, 170);
    m_f_baleine.set_bg_color(BLANC);
    m_f_baleine.set_moveable();
    m_f_baleine.add_child(m_baleine);
    m_baleine.set_pic_name("baleine.bmp");

    m_fond2.add_child( m_f_plancton );
    m_f_plancton.set_frame(140, 0, 170,170);
    m_f_plancton.set_bg_color(BLANC);
    m_f_plancton.set_moveable();
    m_f_plancton.add_child(m_plancton);
    m_plancton.set_pic_name("plancton.bmp");

    m_fond2.add_child( m_f_corail );
    m_f_corail.set_frame(425, 300, 170, 170);
    m_f_corail.set_bg_color(BLANC);
    m_f_corail.set_moveable();
    m_f_corail.add_child(m_corail);
    m_corail.set_pic_name("corail.bmp");

    ///Construction des arcs orientés

    m_fond2.add_child( m_corail_poisson );
    m_corail_poisson.attach_from(m_f_corail);
    m_corail_poisson.attach_to(m_f_poisson);
    m_corail_poisson.reset_arrow_with_bullet();

    m_fond2.add_child( m_corail_plancton );
    m_corail_plancton.attach_from(m_f_corail);
    m_corail_plancton.attach_to(m_f_plancton);
    m_corail_plancton.reset_arrow_with_bullet();

    m_fond2.add_child( m_plancton_baleine );
    m_plancton_baleine.attach_from(m_f_plancton);
    m_plancton_baleine.attach_to(m_f_baleine);
    m_plancton_baleine.reset_arrow_with_bullet();

    m_fond2.add_child( m_baleine_corail );
    m_baleine_corail.attach_from(m_f_baleine);
    m_baleine_corail.attach_to(m_f_corail);
    m_baleine_corail.reset_arrow_with_bullet();

    m_fond2.add_child( m_poisson_baleine );
    m_poisson_baleine.attach_from(m_f_poisson);
    m_poisson_baleine.attach_to(m_f_baleine);
    m_poisson_baleine.reset_arrow_with_bullet();

    m_fond2.add_child( m_poisson_requin );
    m_poisson_requin.attach_from(m_f_poisson);
    m_poisson_requin.attach_to(m_f_requin);
    m_poisson_requin.reset_arrow_with_bullet();

    m_fond2.add_child( m_requin_corail );
    m_requin_corail.attach_from(m_f_requin);
    m_requin_corail.attach_to(m_f_corail);
    m_requin_corail.reset_arrow_with_bullet();

    m_fond2.add_child( m_poisson_thon);
    m_poisson_thon.attach_from(m_f_poisson);
    m_poisson_thon.attach_to(m_f_thon);
    m_poisson_thon.reset_arrow_with_bullet();

    m_fond2.add_child( m_thon_requin);
    m_thon_requin.attach_from(m_f_thon);
    m_thon_requin.attach_to(m_f_requin);
    m_thon_requin.reset_arrow_with_bullet();

    m_fond2.add_child( m_requin_corail);
    m_requin_corail.attach_from(m_f_requin);
    m_requin_corail.attach_to(m_f_corail);
    m_requin_corail.reset_arrow_with_bullet();

    m_fond2.add_child( m_thon_phoque);
    m_thon_phoque.attach_from(m_f_thon);
    m_thon_phoque.attach_to(m_f_phoque);
    m_thon_phoque.reset_arrow_with_bullet();

    m_fond2.add_child( m_phoque_corail );
    m_phoque_corail.attach_from(m_f_phoque);
    m_phoque_corail.attach_to(m_f_corail);
    m_phoque_corail.reset_arrow_with_bullet();



    ///Information écrite
    ///Nom des sommets
    m_f_thon.add_child( m_nom_thon );
    m_nom_thon.set_message("THON");
    m_nom_thon.set_gravity_y(grman::GravityY::Down );

    m_f_phoque.add_child( m_nom_phoque );
    m_nom_phoque.set_message("PHOQUE");
    m_nom_phoque.set_gravity_y(grman::GravityY::Down );

    m_f_requin.add_child( m_nom_requin );
    m_nom_requin.set_message("REQUIN");
    m_nom_requin.set_gravity_y(grman::GravityY::Down );

    m_f_poisson.add_child( m_nom_poisson );
    m_nom_poisson.set_message("POISSON");
    m_nom_poisson.set_gravity_y(grman::GravityY::Down );

    m_f_corail.add_child( m_nom_corail );
    m_nom_corail.set_message("CORAIL");
    m_nom_corail.set_gravity_y(grman::GravityY::Down );

    m_f_plancton.add_child( m_nom_plancton );
    m_nom_plancton.set_message("PLANCTON");
    m_nom_plancton.set_gravity_y(grman::GravityY::Down );

    m_f_baleine.add_child( m_nom_baleine );
    m_nom_baleine.set_message("BALEINE");
    m_nom_baleine.set_gravity_y(grman::GravityY::Down );



    /// Dans ce sous cadre on ajoute 2 ascenseurs verticaux
    m_f_thon.add_child( m_pop_thon );
    m_pop_thon.set_gravity_x(grman::GravityX::Left);
    m_pop_thon.set_bg_color(BLANC);
    m_pop_thon.set_range(1, 20,true);
    m_pop_thon.set_frame(2,10,15,70);
    m_pop_thon.set_value(10);
    m_pop_thon.interact_focus();

    m_f_phoque.add_child( m_pop_phoque );
    m_pop_phoque.set_gravity_x(grman::GravityX::Left);
    m_pop_phoque.set_bg_color(BLANC);
    m_pop_phoque.set_range(1, 20,true);
    m_pop_phoque.set_frame(2,10,15,70);
    m_pop_phoque.set_value(10);
    m_pop_phoque.interact_focus();

    m_f_requin.add_child( m_pop_requin );
    m_pop_requin.set_gravity_x(grman::GravityX::Left);
    m_pop_requin.set_bg_color(BLANC);
    m_pop_requin.set_range(1, 20,true);
    m_pop_requin.set_frame(2,10,15,70);
    m_pop_requin.set_value(10);
    m_pop_requin.interact_focus();

    m_f_poisson.add_child( m_pop_poisson );
    m_pop_poisson.set_gravity_x(grman::GravityX::Left);
    m_pop_poisson.set_bg_color(BLANC);
    m_pop_poisson.set_range(1, 20,true);
    m_pop_poisson.set_frame(2,10,15,70);
    m_pop_poisson.set_value(10);
    m_pop_poisson.interact_focus();

    m_f_corail.add_child( m_pop_corail );
    m_pop_corail.set_gravity_x(grman::GravityX::Left);
    m_pop_corail.set_bg_color(BLANC);
    m_pop_corail.set_range(1, 20,true);
    m_pop_corail.set_frame(2,10,15,70);
    m_pop_corail.set_value(10);
    m_pop_corail.interact_focus();

    m_f_plancton.add_child( m_pop_plancton );
    m_pop_plancton.set_gravity_x(grman::GravityX::Left);
    m_pop_plancton.set_bg_color(BLANC);
    m_pop_plancton.set_range(1, 20,true);
    m_pop_plancton.set_frame(2,10,15,70);
    m_pop_plancton.set_value(10);
    m_pop_plancton.interact_focus();

    m_f_baleine.add_child( m_pop_baleine );
    m_pop_baleine.set_gravity_x(grman::GravityX::Left);
    m_pop_baleine.set_bg_color(BLANC);
    m_pop_baleine.set_range(1, 20,true);
    m_pop_baleine.set_frame(2,10,15,70);
    m_pop_baleine.set_value(10);
    m_pop_baleine.interact_focus();


}


Affichage2::~Affichage2()
{
    //dtor
}

void Affichage2::update2()
{

    /// Si tous les widgets dépendants de l'objet sont dans une top box
    /// alors ce seul appel suffit (la propagation d'updates se fait ensuite automatiquement)
    m_fond2.update();




}

/*void Affichage::add_img(std::string image)
{

    m_fond.add_child( m_orque );
    m_orque.set_pic_name("orque.bmp");
    m_orque.set_posx(120);
    m_orque.set_posy(30);

}*/

