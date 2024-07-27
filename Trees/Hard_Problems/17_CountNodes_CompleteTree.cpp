/*

As the tree is complete, all levels except the last level will have maximum number
of nodes

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int left(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }
    int right(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode *root)
    {
        int l = left(root);
        int h = right(root);
        if (l == h)
        {
            return (1 << l) - 1;
        }
        l = countNodes(root->left);
        h = countNodes(root->right);
        return 1 + l + h;
    }
};