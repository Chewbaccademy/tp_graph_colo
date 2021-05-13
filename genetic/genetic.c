#include "genetic.h"

/**
 * \brief test if 2 nodes have the same color
 * 
 * \param myGraph the colored graph
 * \param a the 1st node
 * \param b the 2nd node
 * 
 * \return 1 if nodes have the same color, 0 otherwise
 */
int isSameColor(graph_colo myGraph, node a, node b){
    return myGraph->colors[a - 1] == myGraph->colors[b - 1];
}

/**
 * \brief calculates the number of edges which link two vertex with the same color
 * 
 * \param myGraph colored graph the function is testing
 * 
 * \return int : number of interferences, ie : the number of edges which link two vertex with the same color
 * 
 */
int nbInterferences(graph_colo myGraph) {

    unsigned int interferences = 0;
    unsigned int size = myGraph->g->size;

    for (int i = 1; i <= size; i++){
        for (int j = 1; j <= i; j++){
            interferences += myGraph->g->content[i - 1][j - 1] && isSameColor(myGraph, i, j);
        }
    }

    return interferences;

}
/**
 * \brief return the graphs with the minimum interferences in the population
 * 
 * \param population the population we test
 * \param taille size of the population
 * 
 * \return 
 */
graph_colo* minInterferences(graph_colo* population, unsigned int taille){

    graph_colo* minimums = (graph_colo*) malloc(sizeof(graph_colo) * taille);

    

}

/**
 * \brief return 1 if int is in an array, 0 otherwise
 * 
 * \param arrayInt the array we test
 * \param taille size of the array
 * \param test int we test
 * 
 * \return 1 if int is in an array, 0 otherwise
 */
int isIntInArray(int* arrayInt, int taille, int test){
    for(int i = 0; i < taille; i++){
        if(arrayInt[i] == test){
            return 1;
        }
    }
    return 0;
}

/**
 * \brief return the number of different colors int the colored graph
 * 
 * \param myGraph the colored graph
 * 
 * \return int : the number of distinct colors
 */
int nbColors(graph_colo myGraph) {

    int taille = myGraph->g->size;
    int* colors = (int*) malloc(taille * sizeof(int));
    int nbColors = 0;
    int color;

    for(int i = 0; i < taille; i++){

        color = myGraph->colors[i];
        if(!isIntInArray(colors, taille, color)){
            nbColors++;
            colors[i] = color;
        }
    }

    free(colors);
    return nbColors;
}

/**
 * \brief display a table of graph_colo
 * 
 * \param tableGraphColo the table to display
 * \param taille size of the table
 * 
 * \return void
 * 
 */
void afficheTableDeGraphColo(const graph_colo* tableGraphColo, unsigned int taille){
    printf("debut table : [\n");

    for(int i = 0; i < taille; i++){
        printf("%d : \n", i);
        printGraphColo(tableGraphColo[i]);
    }
    printf("] : fin de table\n");
}


/**
 * \brief genereate a primary population of colored graph
 * 
 * \param n number of element in the primary population
 * \param filename name of the file from which we load the graph
 * 
 * \return a table of colored graph = population
 */
graph_colo* generatePopulation(unsigned int n, char* filename){

    graph_colo* table_graph_colo = (graph_colo*) malloc(sizeof(graph_colo) * n);

    graph myGraph;
    graph_colo myGraphColo;
    
    for(int i = 0; i < n; i++){
        myGraph = readGraph(filename);
        myGraphColo = createGraphColo(myGraph->size);
        myGraphColo->g = myGraph;

        colorColoredGraphWithRandomColoredColor(myGraphColo);
        table_graph_colo[i] = myGraphColo;
    }

    return table_graph_colo;

}

/**
 * \brief create puml files to visualize all the graphs in the population
 * 
 * \param table_graph_colo the population
 * \param taille size of the population
 * 
 * \return void
 * 
 */
void writePumlPop(graph_colo* table_graph_colo, unsigned int taille){
    char filename[BUFFER_SIZE];
    char number[BUFFER_SIZE];
    int cpt;
    for(int i = 0; i < taille; i++){
        filename[0] = 'r';
        filename[1] = 'e';
        filename[2] = 's';
        itoa(i, number, 10);
        cpt = 0;
        while(number[cpt] != '\0'){
            filename[3 + cpt] = number[cpt];
            cpt++;
        }
        cpt += 3;
        filename[cpt] = '.';
        filename[cpt + 1] = 'p';
        filename[cpt + 2] = 'u';
        filename[cpt + 3] = 'm';
        filename[cpt + 4] = 'l';
        filename[cpt + 5] = '\0';

        writePumlColo(filename, table_graph_colo[i]);
    }
}

/**
 * \brief this function select the best graphs (with less interference and less color)
 * 
 * \param population the population
 * \param keeping_n number of population we keep
 * 
 * \return graph_colo* the polution kept
 */
graph_colo* selection(const graph_colo population, unsigned int keeping_n){

    graph_colo* new_population = (graph_colo*) malloc(keeping_n * sizeof(graph_colo));
    int nbAjoute = 0;

    


}