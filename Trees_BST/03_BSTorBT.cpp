#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    bool func(TreeNode*root, TreeNode*mini, TreeNode*maxi){
        if(!root) return true;
        if((mini && root->val <= mini->val) || (maxi && root->val >= maxi->val)) return false;
        return func(root->left,mini,root) && func(root->right,root,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return func(root,NULL,NULL);
    }
};