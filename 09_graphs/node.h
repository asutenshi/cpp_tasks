#ifndef _NODE_H
#define _NODE_H

#include <string>
#include <set>
#include "types.h"

class NodeException {};

class Node
{
    std::string name;
    std::set<Node*> neighbours;
    void addNeighbour(Node* neighbour);
    void removeNeighbour(Node* neighbour);
    
    public:
        // Для чего использовать список инициализации?
        Node(const std::string& aname) : name(aname) {};
        const std::string& getName() const;
        node_iterator nb_begin() const;
        node_iterator nb_end() const;
        friend class Graph;
        friend std::ostream& operator <<(std::ostream& out, const Node& node);
};

#endif