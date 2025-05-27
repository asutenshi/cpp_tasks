#ifndef _NODE_H
#define _NODE_H

#include <unordered_map>
#include <iostream>

// Предварительное объявление для friend
class SuffixTree; 

using namespace std;

class Node
{
    Node* suff_link;
    Node* parent;
    unordered_map<char, Node*> children;
    // Left and right indexes of internal string
    int l; 
    int r;

    // ASK: What i need to do with sufflinks?
    Node();
    Node(Node* parent_, int l_, int r_);
    Node(Node* parent_, unordered_map<char, Node*> children_, int l_, int r_);
    int len();

    public:
        friend class SuffixTree;
        friend ostream& operator <<(ostream &out, const Node& node);
        // TODO: remove
        friend ostream& operator <<(ostream &out, const SuffixTree& tree);
};

#endif