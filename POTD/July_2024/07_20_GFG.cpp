#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

class Solution {
  public:
    void func(Node*root,Node*pre){
        if(!root) return;
        if(root->left&&!root->right){
            if(pre->left==root){
                pre->left=root->left;
                delete(root);
                func(pre->left,pre);
            }else{
                pre->right=root->left;
                delete(root);
                func(pre->right,pre);
            }
            return;
        }
        if(root->right&&!root->left){
            if(pre->left==root){
                pre->left=root->right;
                delete(root);
                func(pre->left,pre);
            }else{
                pre->right=root->right;
                delete(root);
                func(pre->right,pre);
            }
            return;
        }
        func(root->left,root);
        func(root->right,root);
    }
    Node *RemoveHalfNodes(Node *root) {
        while(root && !root->left && root->right) {Node*temp = root;root=root->right;delete(temp);}
        while(root && !root->right && root->left) {Node*temp = root;root=root->left;delete(temp);}
        if(!root) return NULL;
        func(root->left,root);
        func(root->right,root);
        return root;
    }
};