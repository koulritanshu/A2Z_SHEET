#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BRUTE
{
public:
    string path = "";
    void func(TreeNode *root, string curr, TreeNode *target)
    {
        if (path != "")
            return;
        if (!root)
            return;
        if (root == target)
        {
            path = curr;
            return;
        }
        func(root->left, curr + 'L', target);
        func(root->right, curr + 'R', target);
    }
    void find(vector<int> &ans, TreeNode *node, int dist)
    {
        if (dist < 0)
            return;
        if (!node)
            return;
        if (dist == 0)
        {
            ans.push_back(node->val);
            return;
        }
        find(ans, node->left, dist - 1);
        find(ans, node->right, dist - 1);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        func(root, "", target);
        vector<int> ans;
        int ind = 0;
        while (root != target)
        {
            int curr = path.size() - ind;
            if (curr == k)
            {
                ans.push_back(root->val);
            }
            else if (curr < k)
            {
                int req = k - curr;
                if (path[ind] == 'L')
                {
                    find(ans, root->right, req - 1);
                }
                else
                {
                    find(ans, root->left, req - 1);
                }
            }
            if (path[ind] == 'L')
            {
                root = root->left;
            }
            else if (path[ind] == 'R')
            {
                root = root->right;
            }
            ind++;
        }
        find(ans, target, k);
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class OPTIMAL
{
public:
    // SOLVING USING BFS
    void func(TreeNode *root, TreeNode *parent, map<TreeNode *, TreeNode *> &mp)
    {
        if (!root)
            return;
        mp[root] = parent;
        func(root->left, root, mp);
        func(root->right, root, mp);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode *, TreeNode *> mp;
        func(root->left, root, mp);
        func(root->right, root, mp);
        queue<pair<TreeNode *, int>> q;
        map<TreeNode *, bool> vis;
        q.push({target, k});
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            vis[curr] = true;
            if (dist == 0)
            {
                ans.push_back(curr->val);
            }
            else
            {
                if (curr->left)
                {
                    if (vis[curr->left] != true)
                    {
                        q.push({curr->left, dist - 1});
                    }
                }
                if (curr->right)
                {
                    if (vis[curr->right] != true)
                    {
                        q.push({curr->right, dist - 1});
                    }
                }
                if (mp.find(curr) != mp.end())
                {
                    if (vis[mp[curr]] != true)
                    {
                        q.push({mp[curr], dist - 1});
                    }
                }
            }
        }
        return ans;
    }
};