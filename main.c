#include "./parser/parser.h"

int main(int argc, char const *argv[])
{
    graph myGraph = readGraph("./assets/1-FullIns_3.col");

    printGraph(myGraph);

    writePuml("res.puml", myGraph);

    return 0;
}
