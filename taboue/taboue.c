#include "./taboue.h"

/**
 * \brief set a random color to a node on a colored graph
 * 
 * \param myGraph the colored graph we are working on
 * \param x the node we change the color
 * 
 * \return void
 */
void changeAColor(graph_colo myGraph, node x){
    color col = (rand() % myGraph->g->size) + 1;
    setColor(myGraph, x, col);
}

/**
 * \brief give the number of edges which link to vertexes with the same color
 * 
 * \param myGraph the colored graph we want the interferences
 * 
 * \return int : the number of interferences
 */
int nbInterferences(graph_colo myGraph){
    int nbInterferences = 0;

    for (node a = 1; a <= myGraph->g->size; a++){

        for(node b = 1; b <= a; b++){

            nbInterferences += (myGraph->colors[a] == myGraph->colors[b]) && myGraph->g->content[a][b];

        }

    }

    return nbInterferences;

}