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

// reverse the nodes at every alternate index

void zigZag(TreeNode *root, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            int index = i;
            if (!leftToRight)
                index = size - 1 - i;
            row[index] = front->val;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(row);
    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    zigZag(root, ans);
    return ans;
}