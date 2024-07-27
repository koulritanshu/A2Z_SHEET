#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return lowestCommonAncestor(root,q,p);
        while(root){
            if(root->val >= p->val && root->val<=q->val) return root;
            else if(root->val > p->val && root->val > q->val) root=root->left;
            else root=root->right;
        }
        return NULL;
    }
};