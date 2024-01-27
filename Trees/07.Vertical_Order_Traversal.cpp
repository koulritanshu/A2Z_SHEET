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
    void func(TreeNode *root, map<int, map<int, multiset<int>>> &mp, int x, int y)
    {
        if (!root)
            return;
        (mp[x])[y].insert(root->val);
        func(root->left, mp, x - 1, y + 1);
        func(root->right, mp, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        func(root, mp, 0, 0);
        vector<vector<int>> ans;
        for (auto i : mp)
        {
            vector<int> v;
            for (auto j : i.second)
            {
                for (auto x : j.second)
                {
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};