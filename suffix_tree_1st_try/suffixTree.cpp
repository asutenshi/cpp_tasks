#include "suffixTree.h"
#include "node.h"

using namespace std;

SuffixTree::SuffixTree() :
    s(""), start_ind(0), end_ind(-1), 
    nodes(), curr(), root(nullptr) {}

SuffixTree::SuffixTree(string s_) :
    s(s_), start_ind(0), end_ind(s_.length()), 
    nodes(), curr(), root(nullptr) { buildTree(); }

SuffixTree::SuffixTree(string s_, int start_ind_, int end_ind_) :
    s(s_), start_ind(start_ind_), end_ind(end_ind_), 
    nodes(), curr(), root(nullptr) 
{
    if (start_ind < 0 || start_ind > end_ind || start_ind > s.length())
    {
        // TODO: write exceptions
        throw SuffixTreeException();
    }

    if (end_ind < 0 || end_ind > start_ind || end_ind > s.length())
    {
        // TODO: write exceptions
        throw SuffixTreeException();
    }
}

void SuffixTree::buildTree()
{
    root = new Node();
    curr.set_curr(root);

    for (int i = start_ind; i < end_ind; i++)
    {
        // cout << "Suffixtree at i = " << i << ' ' << s[i] << endl << *this;
        cout << "Curr1 = " << s.substr(curr.curr_node->l, curr.curr_node->r) << " at " << curr.curr_ind << endl;
        // cout << "-------------------------------" << endl;
        if (curr.curr_node->children.find(s[i]) != curr.curr_node->children.end() || 
                (s[i] == s[curr.curr_node->l + curr.curr_ind] && curr.curr_node->l + curr.curr_ind <= curr.curr_node->r))
        {
            if (curr.curr_ind == 0)
            {
                curr.curr_node = curr.curr_node->children[s[i]];
            }
            curr.curr_ind += 1;
        }
        else
        {
            while (curr.curr_node->children.find(s[i]) == curr.curr_node->children.end())
            {
                // отпочковываемся
                if (curr.curr_node->len() == curr.curr_ind)
                {
                    Node* child = new Node(curr.curr_node, i, end_ind - 1);
                    curr.curr_node->children.insert({s[i], child});
                    nodes.insert(child);
                    curr.curr_node->suff_link = move_curr(curr, s[i]).curr_node;
                }
                else
                {
                    curr.curr_node->parent = new Node(curr.curr_node->parent, curr.curr_node->l, curr.curr_node->l + curr.curr_ind - 1);
                    nodes.insert(curr.curr_node->parent);
                    curr.curr_node->l += curr.curr_ind;
                    curr.curr_node->parent->children.insert({s[curr.curr_node->l], curr.curr_node});
                    curr.curr_node = curr.curr_node->parent;
                    curr.curr_ind = curr.curr_node->len();
                    cout << "debug1: " << curr.curr_node->parent->children[s[curr.curr_node->l]] << endl;
                    curr.curr_node->parent->children[s[curr.curr_node->l]] = curr.curr_node;
                    cout << "debug2: " << curr.curr_node->parent->children[s[curr.curr_node->l]] << endl;
                }
            }
        }
        cout << "Suffixtree at i = " << i << ' ' << s[i] << endl << *this;
        cout << "Curr2 = " << s.substr(curr.curr_node->l, curr.curr_node->r) << " at " << curr.curr_ind << endl;
        cout << "-------------------------------" << endl;
    }
    cout << "Curr = " << s.substr(curr.curr_node->l, curr.curr_node->r) << " at " << curr.curr_ind << endl;
}

SuffixTree::Current SuffixTree::move_curr(Current& curr, char c)
{
    // TODO: check curr_ind. It should be set to 0
    int temp_l = curr.curr_node->l + 1;
    int temp_r = curr.curr_node->r;
    string temp_s;    
    
    if (temp_l > temp_r)
    {
        temp_s = "";
    }
    else
    {
        temp_s = s.substr(temp_l, curr.curr_node->len() - 1);
    }
    
    if (curr.curr_node == root)
    {
        return curr;
    }
    else if (curr.curr_node->parent == root)
    {
        curr.curr_node = root;
        curr.curr_ind = 0;
        return curr;
    }
    else if (curr.curr_node->parent->suff_link != nullptr)
    {
        curr.curr_node = curr.curr_node->parent->suff_link;
    }
    else
    {
        throw SuffixTreeException();
    }

    if (curr.curr_node->children.find(temp_s[0]) == curr.curr_node->children.end())
    {
        Node* child = new Node(curr.curr_node, temp_l, temp_r);
        nodes.insert(child);
        curr.curr_node->children.insert({s[temp_l], child});
        curr.curr_node = child;
        curr.curr_ind = temp_s.size() - 1;
    }
    else
    {
        curr.curr_node = curr.curr_node->children[temp_s[0]];
        while (curr.curr_node->r - curr.curr_node->l + 1 < temp_s.size())
        {
            temp_s = temp_s.substr(curr.curr_node->r - curr.curr_node->l);
            curr.curr_node = curr.curr_node->children[temp_s[0]];
        }
        curr.curr_ind += temp_s.size();
    }
    return curr;
}

ostream& operator <<(ostream &out, const SuffixTree& tree)
{
    for (Node* node : tree.nodes)
    {
        cout << node << "->" << tree.s.substr(node->l, node->len()) << ' ' << *node << "->" << tree.s.substr(node->parent->l, node->parent->len()) << endl;
    }
    return out;
}