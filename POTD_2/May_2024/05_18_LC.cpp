#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};

class Solution
{
public:
    int moves;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftCoins = dfs(root->left);
        int rightCoins = dfs(root->right);
        moves += abs(leftCoins) + abs(rightCoins);       // number of moves required
        return (root->val - 1) + leftCoins + rightCoins; // how many coins can current node give to parent
    }
    int distributeCoins(TreeNode *root)
    {
        moves = 0;
        dfs(root);
        return moves;
    }
};