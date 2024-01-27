#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode()
    {
        left = right = NULL;
        val = 0;
    }
};

class Solution
{
public:
    bool func(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        if (!func(p->left, q->right) || !func(p->right, q->left))
        {
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root->left && root->right)
            return false;
        if (!root->right && root->left)
            return false;
        return func(root->left, root->right);
    }
};