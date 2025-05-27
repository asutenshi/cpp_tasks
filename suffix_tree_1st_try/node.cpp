#include "node.h"

using namespace std;

Node::Node() : suff_link(nullptr), parent(nullptr), 
    children(), l(0), r(-1) {}

Node::Node(Node* parent_, int l_, int r_) : suff_link(nullptr), parent(parent_), 
    l(l_), r(r_) {}

Node::Node(Node* parent_, unordered_map<char, Node*> children_, int l_, int r_) : 
    suff_link(nullptr), parent(parent_), children(children_), l(l_), r(r_) {}

int Node::len()
{
    return r - l + 1;
}

ostream& operator <<(ostream &out, const Node& node)
{
    cout << "l = " << node.l << " r = " << node.r << " parent = " << node.parent;
    return out;
}