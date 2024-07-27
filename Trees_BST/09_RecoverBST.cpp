#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev!=NULL && root->val < prev->val){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first=middle=last=NULL;
        inorder(root);
        if(last==NULL) swap(first->val,middle->val);
        else swap(first->val,last->val);
    }
};