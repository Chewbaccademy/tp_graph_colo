#include "./parser/parser.c"
#include "./genetic/genetic.c"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int TAILLE = 10;
    
    graph_colo* table_graph_colo =  generatePopulation(TAILLE, "./assets/1-FullIns_3.col");

    /* afficheTableDeGraphColo(table_graph_colo, TAILLE);
 */

    afficheTableDeGraphColo(table_graph_colo, TAILLE);

    for(int i = 0; i < TAILLE; i++){
        printf("interferences du graph : %d\n", nbInterferences(table_graph_colo[i]));
        printf("colors du graph : %d\n", nbColors(table_graph_colo[i]));
    }

    writePumlPop(table_graph_colo, TAILLE);

    return 0;
}
