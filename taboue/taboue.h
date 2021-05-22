#ifndef TABOUE_H
#define TABOUE_H

#include "../parser/parser.c"

/**
 * \brief set a random color to a node on a colored graph
 * 
 * \param myGraph the colored graph we are working on
 * \param x the node we change the color
 * 
 * \return void
 */
void changeAColor(graph_colo myGraph, node x);

/**
 * \brief give the number of edges which link to vertexes with the same color
 * 
 * \param myGraph the colored graph we want the interferences
 * 
 * \return int : the number of interferences
 */
int nbInterferences(graph_colo myGraph);

#endif