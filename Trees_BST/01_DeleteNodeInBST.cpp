#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            return helper(root,key);
        }
        if(root->val>key) root->left=deleteNode(root->left,key);
        if(root->val<key) root->right=deleteNode(root->right,key);
        return root;
    }
    TreeNode* helper(TreeNode* root, int target){
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        else if(root->left==NULL||root->right==NULL){
            TreeNode* ans;
            if(root->left==NULL) ans = root->right;
            else ans=root->left;
            delete(root);
            return ans;
        }
        else{
            TreeNode* node = root->right;
            while(node->left) node=node->left;
            int temp = node->val;
            node->val=root->val;
            root->val=temp;
            root->right=deleteNode(root->right,target);
            return root;
        }
    }
};