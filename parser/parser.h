#ifndef PARSER_H
#define PARSER_

#include "../graph/graph.h"

#define BUFFER_SIZE 256



/**
 * \brief Parse graph informations from file in a new graph
 * 
 * \param filename: the file holding the informations
 * 
 * \return: the graph obtained
 */
graph readGraph(char* filename);

void writePuml(char* filename, graph g);


#endif 