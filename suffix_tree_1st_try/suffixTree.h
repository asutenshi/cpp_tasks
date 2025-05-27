#ifndef _SUFFIX_TREE_H
#define _SUFFIX_TREE_H

#include <string>
#include <set>

#include "node.h"

using namespace std;

class SuffixTreeException {};

class SuffixTree
{
    struct Current
    {
        Node* curr_node;
        // TODO: translate
        int curr_ind; // индекс строки ноды на котой я стою

        Current() : curr_node(nullptr), curr_ind(0) {}
        void set_curr(Node* curr_node)
        {
            this->curr_node = curr_node;
            this->curr_ind = 0;
        }
        void set_curr(Node* curr_node, int curr_ind)
        {
            this->curr_node = curr_node;
            this->curr_ind = curr_ind;
        }
    };

    string s; // internal string
    int start_ind;
    int end_ind;
    set<Node*> nodes;
    Current curr;
    Node* root;

    void buildTree();
    Current move_curr(Current& curr, char c);

    public:
        SuffixTree();
        SuffixTree(string s_);
        SuffixTree(string s_, int start_ind_, int end_ind_);
        friend class Node;
        friend ostream& operator <<(ostream &out, const SuffixTree& tree);
};

#endif