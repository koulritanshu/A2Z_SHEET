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

class Approach1
{
    // Time Complexity -> O(n + n + n) = O(3*n) -- O(n)
    // Space Complexity -> O(n + n) = O(2*n) -- O(n)
public:
    vector<int> v;
    void replace(TreeNode *root)
    {
        if (!root)
            return;
        replace(root->left);
        root->val = v[root->val];
        replace(root->right);
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        root->val = v.size() - 1;
        inorder(root->right);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        inorder(root);
        for (int i = v.size() - 2; i >= 0; i--)
        {
            v[i] += v[i + 1];
        }
        replace(root);
        return root;
    }
};

class RecursiveInorderTraversal {
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
public:
    int sum = 0;
    void inorder(TreeNode*root){
        if(!root) return;
        inorder(root->right);
        sum += root->val;
        root->val = sum;
        inorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
};

class IterativeInorderTraversal {
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
public:
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        stack<TreeNode*> st;
        TreeNode*temp = root;
        while(temp || !st.empty()){
            if(temp){
                st.push(temp);
                temp = temp->right;
            }
            else{
                TreeNode* tp = st.top();
                st.pop();
                nodeSum += tp->val;
                tp->val = nodeSum;
                if(tp->left){
                    temp = tp->left;
                }
            }
        }
        return root;
    }
};