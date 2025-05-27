#ifndef _CURRENT_H
#define _CURRENT_H

class SuffixTree;

class Current
{
    int node_ind, edge_ind;

    public:
        Current(int node_ind, int edge_ind) : 
            node_ind(node_ind), edge_ind(edge_ind) {}
        friend class SuffixTree;
};

#endif