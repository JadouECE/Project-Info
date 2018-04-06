#include "graph.h"
#include <sstream>

namespace patch
{
    template<typename T> std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm<<n;
        return stm.str();
    }
}

/***************************************************
                    GRAPH
****************************************************/

/*/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(80,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(908,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);
}*/


/// Constructeur de graphe qui construit les arcs et les sommets en les stockant dans des vectors d'arc et sommet
Graph::Graph()
{

   /* Sommet jade("Jade", 1);
    Sommet sousou("Clement",1);
    Sommet sousou("Bendo",3);
    this->m_sommet.push_back(&jade);
    this->m_sommet.push_back(&sousou);
    this->m_sommet.push_back(&bendo);
    //std::cout<<this->m_sommet[0]->m_nom<<std::endl;
    //std::cout<<this->m_sommet[1]->m_nom<<std::endl;
    Arc amour(this->m_sommet[0],this->m_sommet[1], 1000000000);
    Arc amitié(this->m_sommet[1],this->m_sommet[2], 10000);
    Arc ambiguité(this->m_sommet[2],this->m_sommet[0], 10);
    this->m_arc.push_back(&amour);
    this->m_arc.push_back(&amitié);
    this->m_arc.push_back(&ambiguité);
    std::cout<<this->m_arc[0]->m_from->m_nom<<std::endl;
*/
    /*ifstream info_graph("banquise_sommet.txt",ios::in);
    info_graph.seekg(0,ios::beg);
    ///Récupération nombre arete
    getline(info_graph,m_nb_arc);
    nb_arc=m_nb_arc;
    ///Recup nombre sommet
    getline(info_graph,m_nb_sommet);
    nb_sommet=m_nb_sommet;

    for (int i=0, i<nb_sommet, i++)    ///Recuperation des données de chaque sommet et construit chaque sommet
    {

        getline(info_graph, s_nom);
        getline(info_graph,s_type);
        getline(info_graph, s_index);
        getline(info_graph, s_population_t);
        getline(info_graph, s_population_tpost);
        getline(info_graph, s_regulation);
        getline(info_graph, s_nom_predateur);

        m_sommet.push_back(new Sommet(s_nom , s_type , s_index , s_population_t , s_population_tpost , s_regulation , s_nom_predateur));

    }

    for (int j=0, j<nb_arc,j++)      ///Recup données de chaque arc et construit chaque arc
    {
        getline(info_graph, a_nom_from);
        getline(info_graph, a_nom_to);
        getline(info_graph, a_coef);

    m_arc.push_back(new Arc(a_nom_from, a_nom_to ,a_coef));
    }*/
}

   /* m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    // La ligne précédente est en gros équivalente à :
    // m_interface = new GraphInterface(50, 0, 750, 600);

    /// Les sommets doivent être définis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
    add_interfaced_vertex(0, 30.0, 200, 100, "clown1.jpg");
    add_interfaced_vertex(1, 60.0, 400, 100, "clown2.jpg");
    add_interfaced_vertex(2,  50.0, 200, 300, "clown3.jpg");
    add_interfaced_vertex(3,  0.0, 400, 300, "clown4.jpg");
    add_interfaced_vertex(4,  100.0, 600, 300, "clown5.jpg");
    add_interfaced_vertex(5,  0.0, 100, 500, "bad_clowns_xx3xx.jpg", 0);
    add_interfaced_vertex(6,  0.0, 300, 500, "bad_clowns_xx3xx.jpg", 1);
    add_interfaced_vertex(7,  0.0, 500, 500, "bad_clowns_xx3xx.jpg", 2);

    /// Les arcs doivent être définis entre des sommets qui existent !
    // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
    add_interfaced_edge(0, 1, 2, 50.0);
    add_interfaced_edge(1, 0, 1, 50.0);
    add_interfaced_edge(2, 1, 3, 75.0);
    add_interfaced_edge(3, 4, 1, 25.0);
    add_interfaced_edge(4, 6, 3, 25.0);
    add_interfaced_edge(5, 7, 3, 25.0);
    add_interfaced_edge(6, 3, 4, 0.0);
    add_interfaced_edge(7, 2, 0, 100.0);
    add_interfaced_edge(8, 5, 2, 20.0);
    add_interfaced_edge(9, 3, 7, 80.0);*/


/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
/*void Graph::update()
{
    if (!m_interface)
        return;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();

}*/

/*/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);
}*/

/// Aide à l'ajout d'arcs interfacés
/*void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);
}*/

