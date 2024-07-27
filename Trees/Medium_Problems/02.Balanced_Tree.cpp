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

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;
    return (check(root) != -1);
}

int check(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = check(root->left);
    if (lh == -1)
        return -1;
    int rh = check(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}