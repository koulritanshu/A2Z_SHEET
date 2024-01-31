#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[27];

    bool isLeaf;
};

class Solution
{
public:
    void insert(struct TrieNode *root, string key)
    {
        TrieNode *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children[key[i] - 'a'] == NULL)
                temp->children[key[i] - 'a'] = new TrieNode();
            temp = temp->children[key[i] - 'a'];
        }
        temp->isLeaf = true;
    }
    bool search(struct TrieNode *root, string key)
    {
        for (int i = 0; i < key.size(); i++)
        {
            if (root->children[key[i] - 'a'] == NULL)
                return false;
            root = root->children[key[i] - 'a'];
        }
        if (root->isLeaf)
            return true;
    }
};