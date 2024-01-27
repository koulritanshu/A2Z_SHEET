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

int ans = INT_MIN;
int maxPathSum2(TreeNode *root)
{
    if (!root)
        return 0;
    int left = max(0, maxPathSum2(root->left));
    int right = max(0, maxPathSum2(root->right));
    ans = max(ans, root->val + left + right);
    return max(root->val + left, root->val + right);
}
int maxPathSum(TreeNode *root)
{
    maxPathSum2(root);
    return ans;
}