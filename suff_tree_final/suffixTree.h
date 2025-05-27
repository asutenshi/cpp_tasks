#ifndef _SUFFIX_TREE_H
#define _SUFFIX_TREE_H

#include <vector>
#include <string>
#include <fstream>

#include "node.h"
#include "current.h"

using namespace std;

class SuffixTree
{
    string s;
    int s_length;
    Node* tree;
    int size;

    Current curr;

    public:
        SuffixTree();
        SuffixTree(string s);
        SuffixTree(ifstream& in);
        ~SuffixTree();

        SuffixTree& operator=(const SuffixTree& other);
        SuffixTree(const SuffixTree &other);


        Current moveDown(Current curr, int l, int r);
        int split(Current curr);
        int getLink(int id);
        void treeExtend(int pos);
        void build_tree();
        bool contain(string find);
        float compare(string comp);

        friend ostream& operator <<(ostream& out, const SuffixTree& tree);
};

#endif