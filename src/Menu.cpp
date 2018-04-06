#include "Menu.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Menu::Menu()
{

    m_top_box.set_dim(1000,558);
    m_top_box.set_bg_color(GRISCLAIR);

    m_top_box.add_child( m_fondMenu );
    m_fondMenu.set_frame(0,0,1000,558);
    m_fondMenu.set_bg_color(GRISCLAIR);
    m_fondMenu.add_child( m_evolve );
    m_evolve.set_pic_name("evolve1.jpg");


    /// 1er bouton avec une image
    m_fondMenu.add_child( m_bouton1 );
    m_bouton1.set_dim(220,42);
    m_bouton1.set_pos(28,502);
    m_bouton1.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);
    m_bouton1.set_bg_color(BLANC);
    m_bouton1.add_child(m_bouton1_image);
    m_bouton1_image.set_pic_name("Graphe1.jpg");

    ///deuxieme bouton (x,y,largeur,hauteur)

    m_evolve.add_child( m_bouton2 );
    m_bouton2.set_dim(264,49);
    m_bouton2.set_pos(385,493);
    m_bouton2.set_gravity_xy(grman::GravityX::Center, grman::GravityY::Down);
    m_bouton2.set_bg_color(BLANC);
    m_bouton2.add_child(m_bouton2_image);
    m_bouton2_image.set_pic_name("Graphe2.jpg");

    ///troisieme bouton(x,y,largeur,hauteur)

    m_evolve.add_child( m_bouton3 );
    m_bouton3.set_dim(229,47);
    m_bouton3.set_pos(742,488);
    m_bouton3.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_bouton3.set_bg_color(BLANC);
    m_bouton3.add_child(m_bouton3_image);
    m_bouton3_image.set_pic_name("Graphe3.jpg");







}


Menu::~Menu()
{
    //dtor
}


void Menu::update()
{
    m_top_box.update();

}
