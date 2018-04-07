#include "Affichage.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Affichage::Affichage()
{
    ///Construction du fond bleu clair
    m_fond.set_dim(1000,750);
    m_fond.set_bg_color(BLANC);
    m_fond.set_moveable();

    ///Construction des sommets (Box mobiles)

    m_fond.add_child(m_f_orque);
    m_f_orque.set_frame(120, 30, 170,170);
    m_f_orque.set_bg_color(BLANC);
    m_f_orque.set_moveable();
    m_f_orque.add_child( m_orque );
    m_orque.set_pic_name("orque.bmp");

    m_fond.add_child( m_f_phoque );
    m_f_phoque.set_frame(250, 130, 170,170);
    m_f_phoque.set_bg_color(BLANC);
    m_f_phoque.set_moveable();
    m_f_phoque.add_child(m_phoque);
    m_phoque.set_pic_name("phoque.bmp");  ///changer taille image

    m_fond.add_child( m_f_poisson );
    m_f_poisson.set_frame(250, 130, 170, 170);
    m_f_poisson.set_bg_color(BLANC);
    m_f_poisson.set_moveable();
    m_f_poisson.add_child(m_poisson);
    m_poisson.set_pic_name("poisson.bmp");

    m_fond.add_child( m_f_pingouin );
    m_f_pingouin.set_frame(300, 330, 170, 170);
    m_f_pingouin.set_bg_color(BLANC);
    m_f_pingouin.set_moveable();
    m_f_pingouin.add_child(m_pingouin);
    m_pingouin.set_pic_name("pingouin.bmp");

    m_fond.add_child( m_f_krill );
    m_f_krill.set_frame(380, 400, 170, 170);
    m_f_krill.set_bg_color(BLANC);
    m_f_krill.set_moveable();
    m_f_krill.add_child(m_krill);
    m_krill.set_pic_name("krill.bmp");

    m_fond.add_child( m_f_mo );
    m_f_mo.set_frame(250, 130, 170, 170);
    m_f_mo.set_bg_color(BLANC);
    m_f_mo.set_moveable();
    m_f_mo.add_child(m_mo);
    m_mo.set_pic_name("mo.bmp");

    ///Construction des arcs orientés

    m_fond.add_child( m_mo_k );
    m_mo_k.attach_from(m_f_mo);
    m_mo_k.attach_to(m_f_krill);
    m_mo_k.reset_arrow_with_bullet();

    m_fond.add_child( m_k_poisson );
    m_k_poisson.attach_from(m_f_krill);
    m_k_poisson.attach_to(m_f_poisson);
    m_k_poisson.reset_arrow_with_bullet();

    m_fond.add_child( m_k_ping );
    m_k_ping.attach_from(m_f_krill);
    m_k_ping.attach_to(m_f_pingouin);
    m_k_ping.reset_arrow_with_bullet();

    m_fond.add_child( m_poisson_ping );
    m_poisson_ping.attach_from(m_f_poisson);
    m_poisson_ping.attach_to(m_f_pingouin);
    m_poisson_ping.reset_arrow_with_bullet();

    m_fond.add_child( m_ping_phoque );
    m_ping_phoque.attach_from(m_f_pingouin);
    m_ping_phoque.attach_to(m_f_phoque);
    m_ping_phoque.reset_arrow_with_bullet();

    m_fond.add_child( m_ping_orque );
    m_ping_orque.attach_from(m_f_pingouin);
    m_ping_orque.attach_to(m_f_orque);
    m_ping_orque.reset_arrow_with_bullet();

    m_fond.add_child( m_phoque_orque );
    m_phoque_orque.attach_from(m_f_phoque);
    m_phoque_orque.attach_to(m_f_orque);
    m_phoque_orque.reset_arrow_with_bullet();

    m_fond.add_child( m_orque_mo);
    m_orque_mo.attach_from(m_f_orque);
    m_orque_mo.attach_to(m_f_mo);
    m_orque_mo.reset_arrow_with_bullet();

    ///Information écrite
    ///Nom des sommets
    m_f_orque.add_child( m_nom_orque );
    m_nom_orque.set_message("ORQUE");
    m_nom_orque.set_gravity_y(grman::GravityY::Down );

    m_f_phoque.add_child( m_nom_phoque );
    m_nom_phoque.set_message("PHOQUE");
    m_nom_phoque.set_gravity_y(grman::GravityY::Down );

    m_f_pingouin.add_child( m_nom_pingouin );
    m_nom_pingouin.set_message("PINGOUIN");
    m_nom_pingouin.set_gravity_y(grman::GravityY::Down );

    m_f_poisson.add_child( m_nom_poisson );
    m_nom_poisson.set_message("POISSON");
    m_nom_poisson.set_gravity_y(grman::GravityY::Down );

    m_f_krill.add_child( m_nom_krill );
    m_nom_krill.set_message("KRILL");
    m_nom_krill.set_gravity_y(grman::GravityY::Down );

    m_f_mo.add_child( m_nom_mo );
    m_nom_mo.set_message("MAT. ORGANIQUE");
    m_nom_mo.set_gravity_y(grman::GravityY::Down );



    /// Dans ce sous cadre on ajoute 2 ascenseurs verticaux
    m_f_orque.add_child( m_pop_orque );
    m_pop_orque.set_gravity_x(grman::GravityX::Left);
    m_pop_orque.set_bg_color(BLANC);
    m_pop_orque.set_range(1, 20,true);
    m_pop_orque.set_frame(2,10,15,70);
    m_pop_orque.set_value(10);
    m_pop_orque.interact_focus();

    m_f_phoque.add_child( m_pop_pho );
    m_pop_pho.set_gravity_x(grman::GravityX::Left);
    m_pop_pho.set_bg_color(BLANC);
    m_pop_pho.set_range(1, 20,true);
    m_pop_pho.set_frame(2,10,15,70);
    m_pop_pho.set_value(10);
    m_pop_pho.interact_focus();

    m_f_pingouin.add_child( m_pop_ping );
    m_pop_ping.set_gravity_x(grman::GravityX::Left);
    m_pop_ping.set_bg_color(BLANC);
    m_pop_ping.set_range(1, 20,true);
    m_pop_ping.set_frame(2,10,15,70);
    m_pop_ping.set_value(10);
    m_pop_ping.interact_focus();

    m_f_poisson.add_child( m_pop_poisson );
    m_pop_poisson.set_gravity_x(grman::GravityX::Left);
    m_pop_poisson.set_bg_color(BLANC);
    m_pop_poisson.set_range(1, 20,true);
    m_pop_poisson.set_frame(2,10,15,70);
    m_pop_poisson.set_value(10);
    m_pop_poisson.interact_focus();

    m_f_krill.add_child( m_pop_krill );
    m_pop_krill.set_gravity_x(grman::GravityX::Left);
    m_pop_krill.set_bg_color(BLANC);
    m_pop_krill.set_range(1, 20,true);
    m_pop_krill.set_frame(2,10,15,70);
    m_pop_krill.set_value(10);
    m_pop_krill.interact_focus();

    m_f_mo.add_child( m_pop_mo );
    m_pop_mo.set_gravity_x(grman::GravityX::Left);
    m_pop_mo.set_bg_color(BLANC);
    m_pop_mo.set_range(1, 20,true);
    m_pop_mo.set_frame(2,10,15,70);
    m_pop_mo.set_value(10);
    m_pop_mo.interact_focus();


}


Affichage::~Affichage()
{
    //dtor
}

void Affichage::update()
{

    /// Si tous les widgets dépendants de l'objet sont dans une top box
    /// alors ce seul appel suffit (la propagation d'updates se fait ensuite automatiquement)
    m_fond.update();




}

/*void Affichage::add_img(std::string image)
{

    m_fond.add_child( m_orque );
    m_orque.set_pic_name("orque.bmp");
    m_orque.set_posx(120);
    m_orque.set_posy(30);

}*/

