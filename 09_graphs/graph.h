#ifndef _GRAPH_H
#define _GRAPH_H

#include "node.h"
#include "types.h"

// Реализация types.h?

class GraphException {};

class Graph
{
    std::set<Node *> nodes;

    public:
        Graph();
        Graph(std::string filename);
        Graph(std::set<Node*> anodes);
        // Нужно проверять, что добавляемой ноды нет в графе
        void addNode(Node* node);
        Node* findNode(std::string name);
        void removeNode(Node* node);
        void addEdge(Node* begin, Node* end);
        void addEdge(std::string begin, std::string end);
        void removeEdge(Node* begin, Node* end);
        node_iterator begin() const;
        node_iterator end() const;
        friend std::ostream& operator <<(std::ostream& out, const Graph& graph);
        void writeGraphToFile(std::ostream& out) const;
};

#endif