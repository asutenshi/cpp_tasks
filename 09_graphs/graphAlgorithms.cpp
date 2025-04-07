#include <queue>
#include "graphAlgorithms.h"
#include <fstream>
#include <iostream>

bool BFS::connected(Node* begin, Node* end)
{
    std::queue<Node*> nodes;
    nodes.push(begin);
    std::set<Node*> visited;

    while (!nodes.empty())
    {
        Node* next = nodes.front();
        nodes.pop();
        if (end == next) {
            return true;
        } 
        visited.insert(next);
        for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
            if (visited.find(*it) == visited.end())
                nodes.push(*it);
    }
    return false;
}

void writeDisjointGraphs(const Graph& graph)
{
    BFS bfs(graph);

    std::vector<Graph> disjointGraphs;

    std::set<Node*> visited;
    for (node_iterator s_it = graph.begin(); s_it != graph.end(); s_it++)
    {
        std::set<Node*> new_graph;
        for (node_iterator e_it = graph.begin(); e_it != graph.end(); e_it++)
        {
            if (visited.find(*e_it) == visited.end() && bfs.connected((*s_it), (*e_it)))
            {
                new_graph.insert((*e_it));
                visited.insert(*e_it);
            }
        }
        if (new_graph.empty())
            continue;
        else
            disjointGraphs.push_back(Graph(new_graph));
    }

    for (int i = 0; i < disjointGraphs.size(); i++)
    {
        std::string filename("disjointGraph" + std::to_string(i+1));
        std::ofstream out(filename);
        if (!out.is_open())
        {
            throw GraphException();
        }
        std::cout << "Запись подграфа в файл " << filename << std::endl;
        disjointGraphs[i].writeGraphToFile(out);
    }
    std::cout << "Было найдено " << disjointGraphs.size()
         << " не пересекающихся подграфов" << std::endl;
}