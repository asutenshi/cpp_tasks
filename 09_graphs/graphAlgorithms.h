#ifndef _GRAPH_ALGORITHMS_H
#define _GRAPH_ALGORITHMS_H

#include "graph.h"

class BFS
{
    const Graph& graph;

    public:
        BFS(const Graph& agraph) : graph(agraph) {}
        bool connected(Node* begin, Node* end);
};

void writeDisjointGraphs(const Graph& graph);

#endif