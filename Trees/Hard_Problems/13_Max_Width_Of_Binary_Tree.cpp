#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BruteForce
{
public:
    void func(TreeNode *root, map<int, vector<unsigned long long>> &mp, unsigned long long x, int level)
    {
        if (!root)
            return;
        mp[level].push_back(x);
        func(root->left, mp, (unsigned long long)(2 * x) + (unsigned long long)1, level + 1);
        func(root->right, mp, (unsigned long long)(2 * x) + (unsigned long long)2, level + 1);
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        map<int, vector<unsigned long long>> mp;
        func(root, mp, 0, 0);
        unsigned long long ans = 0;
        for (auto i : mp)
        {
            ans = max(ans, i.second[i.second.size() - 1] - i.second[0] + 1);
        }
        return (int)ans;
    }
};

class Optimal
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> qp;
        qp.push({root, 0});
        int ans = 0;
        while (!qp.empty())
        {
            int mmin = qp.front().second;
            int size = qp.size();
            int first = 0, last = 0;
            for (int i = 0; i < size; i++)
            {
                int cur_id = qp.front().second - mmin;
                TreeNode *node = qp.front().first;
                qp.pop();
                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;
                if (node->left)
                {
                    qp.push({node->left, cur_id * 2 + 1});
                }
                if (node->right)
                {
                    qp.push({node->right, cur_id * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};