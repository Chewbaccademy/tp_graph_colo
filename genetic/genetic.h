#ifndef GENETIC_H
#define GENETIC_H

#include "../graph_colo/graph_colo.h"

/**
 * \brief test if 2 nodes have the same color
 * 
 * \param myGraph the colored graph
 * \param a the 1st node
 * \param b the 2nd node
 * 
 * \return 1 if nodes have the same color, 0 otherwise
 */
int isSameColor(graph_colo myGraph, node a, node b);

/**
 * \brief calculate the number of edges which lie two vertex with the same color
 * 
 * \param myGraph colored graph the function is testing
 * 
 * \return int : number of interferences, ie : the number of edges which lie two vertex with the same color
 * 
 */
int nbInterferences(graph_colo myGraph);

/**
 * \brief return the number of different colors int the colored graph
 * 
 * \param myGraph the colored graph
 * \param taille size of the graph (number of vertex)
 * 
 * \return int : the number of distinct colors
 * 
 */
int nbColors(graph_colo myGraph);

/**
 * \brief display a table of graph_colo
 * 
 * \param tableGraphColo the table to display
 * \param taille size of the table
 * 
 * \return void
 * 
 */
void afficheTableDeGraphColo(const graph_colo* tableGraphColo, unsigned int taille);


/**
 * \brief genereate a primary population of colored graph
 * 
 * \param n number of element in the primary population
 * \param filename name of the file from which we load the graph
 * 
 * \return a table of colored graph = population
 */
graph_colo* generatePopulation(unsigned int n, char* filename);


/**
 * \brief create puml files to visualize all the graphs in the population
 * 
 * \param table_graph_colo the population
 * \param taille size of the population
 * 
 * \return void
 * 
 */
void writePumlPop(graph_colo* table_graph_colo, unsigned int taille);


/**
 * \brief this function select the best graphs (with less interference and less color)
 * 
 * \param population the population
 * \param keeping_n number of population we keep
 * 
 * \return graph_colo* the polution kept
 */
graph_colo* selection(const graph_colo population, unsigned int keeping_n);


#endif