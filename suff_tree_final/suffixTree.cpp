#include "suffixTree.h"

SuffixTree::SuffixTree() : curr(0, 0), 
    s(""), s_length(s.size()), tree(nullptr), size(0) {}

SuffixTree::SuffixTree(string s) : curr(0, 0), s(s), s_length(s.length()) 
{
    tree = new Node[2*s_length];
    build_tree();
}

SuffixTree::SuffixTree(ifstream& in) : curr(0, 0) 
{
    if (!in.is_open())
        throw runtime_error("File is not opened");
    s_length = 0;
    char c;
    while (in.get(c))
    {
        s += c;
        ++s_length;
    }
    s += '$';
    ++s_length;
    tree = new Node[2*s_length];
    build_tree();
}

SuffixTree& SuffixTree::operator=(const SuffixTree& other)
{
    if (this == &other)
        return *this;

    delete[] tree;

    s = other.s;
    s_length = other.s_length;
    size = other.size;
    curr = other.curr;

    if (other.tree && other.s_length > 0)
    {
        tree = new Node[2 * s_length];
        for (int i = 0; i < 2 * s_length; ++i)
        {
             if (i < other.size) {
                tree[i] = other.tree[i];
             }
        }
    }
    else
    {
        tree = nullptr;
    }

    return *this;
}

SuffixTree::SuffixTree(const SuffixTree &other) : curr(0, 0)
{
    s = other.s;
    s_length = other.s_length;
    size = other.size;
    curr = other.curr;

    if (other.tree && other.s_length > 0)
    {
        tree = new Node[2 * s_length];
        for (int i = 0; i < other.size; ++i)
        {
            tree[i] = other.tree[i];
        }
    }
    else
    {
        tree = nullptr;
    }
}

SuffixTree::~SuffixTree()
{
    delete[] tree;
}

Current SuffixTree::moveDown(Current curr, int l, int r)
{
    while (l < r)
    {
        if (curr.edge_ind == tree[curr.node_ind].len())
        {
            curr = Current(tree[curr.node_ind].get(s[l]), 0);
            if (curr.node_ind == -1) return curr;
        }
        else
        {
            if (s[tree[curr.node_ind].l + curr.edge_ind] != s[l])
                return Current(-1, -1);
            if (r - l < tree[curr.node_ind].len() - curr.edge_ind)
                return Current(curr.node_ind, curr.edge_ind + r-l);
            l += tree[curr.node_ind].len() - curr.edge_ind;
            curr.edge_ind = tree[curr.node_ind].len();
        }
    }
    return curr;
}

int SuffixTree::split(Current curr)
{
    if (curr.edge_ind == tree[curr.node_ind].len())
        return curr.node_ind;
    if (curr.edge_ind == 0)
        return tree[curr.node_ind].parent;
    Node node = tree[curr.node_ind];
    int id = size++;
    tree[id] = Node(node.l, node.l + curr.edge_ind, node.parent);
    tree[node.parent].get(s[node.l]) = id;
    tree[id].get(s[node.l + curr.edge_ind]) = curr.node_ind;
    tree[curr.node_ind].parent = id; 
    tree[curr.node_ind].l += curr.edge_ind;
    return id;
}

int SuffixTree::getLink(int id)
{
    if (tree[id].suff_link != -1) return tree[id].suff_link;
    if (tree[id].parent == -1) return 0;
    int to = getLink(tree[id].parent);
    return tree[id].suff_link = split(
        moveDown(Current(to, tree[to].len()), 
        tree[id].l + (tree[id].parent==0), 
        tree[id].r)
    ) ;
}

void SuffixTree::treeExtend(int pos)
{
    for (;;)
    {
        Current ncurr = moveDown(curr, pos, pos+1);
        if (ncurr.node_ind != -1)
        {
            curr = ncurr;
            return;
        }

        int mid = split(curr);
        int leaf = size++;
        tree[leaf] = Node(pos, s_length, mid);
        tree[mid].get(s[pos]) = leaf;

        curr.node_ind = getLink(mid);
        curr.edge_ind = tree[curr.node_ind].len();
        if (!mid) break;
    }
}

void SuffixTree::build_tree()
{
    size = 1;
    for (int i = 0; i < s_length; i++)
    {
        treeExtend(i);
    }
}

bool SuffixTree::contain(string find)
{
    curr = Current(0, 0);
    for (int i = 0; i < find.length(); i++)
    {
        if (curr.edge_ind == tree[curr.node_ind].len())
        {
            if (tree[curr.node_ind].get(find[i]) == -1)
                return false;
            curr.node_ind = tree[curr.node_ind].get(find[i]);
            curr.edge_ind = 1;
        }
        else
        {
            if (s[tree[curr.node_ind].l + curr.edge_ind] != find[i])
                return false;
            curr.edge_ind++;
        }
    }
    return true;
}

float SuffixTree::compare(string comp)
{
    float max_suff_size = 0;
    for (int i = 0; i < comp.size(); i++)
    {
        string suff = comp.substr(i, comp.size() - i);
        if (contain(suff) && suff.size() >= max_suff_size)
        {
            max_suff_size = suff.size();
        }
    } 
    return max_suff_size / comp.size() * 100;
}


ostream& operator <<(ostream& out, const SuffixTree& tree)
{
    out << "SuffixTree:" << endl;
    for (int i = 0; i < tree.size; i++)
        out << '\t' << i << "->" << tree.s.substr((tree.tree+i)->l, (tree.tree+i)->len())<< ' ' << *(tree.tree + i) << endl;
    return out;
}