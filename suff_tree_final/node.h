#ifndef _NODE_H
#define _NODE_H

#include <unordered_map>
#include <iostream>

using namespace std;

class SuffixTree;

class Node
{
    int l, r, parent, suff_link;
    unordered_map<char, int> children;

    public:
        Node(int l=0, int r=0, int parent=-1) : 
            l(l), r(r), parent(parent), suff_link(-1) {}
        int len() { return r - l; }
        int& get(char c)
        {
            if (children.find(c) == children.end())
                children[c] = -1;
            return children[c];
        }
        friend class SuffixTree;
        friend ostream& operator <<(ostream& out, const Node& node)
        {
            out << "l=" << node.l << " r=" << node.r << " parent=" << node.parent;
            return out;
        }
        friend ostream& operator <<(ostream& out, const SuffixTree& tree);
};

#endif