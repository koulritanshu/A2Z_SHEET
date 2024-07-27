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

class Inorder_to_vector_to_BST 
{
    // Time Complexity - O(n)
    // Space Complexity - O(n)
public:
    Inorder_to_vector_to_BST()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void inorder(vector<int> &v, TreeNode *root)
    {
        if (!root)
            return;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
    TreeNode *constructBST(vector<int> &v, int st, int ed)
    {
        if (st > ed)
            return NULL;
        int mid = st + (ed - st) / 2;
        int value = v[mid];
        TreeNode *root = new TreeNode(value);
        root->left = constructBST(v, st, mid - 1);
        root->right = constructBST(v, mid + 1, ed);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        inorder(v, root);
        root = constructBST(v, 0, v.size() - 1);
        return root;
    }
};