#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};

struct Node{
    int data;
    Node*next;
};

void make(TreeNode*&root,vector<int>&v,int ind){
    if(ind>=v.size()) return;
    root = new TreeNode(v[ind]);
    make(root->left,v,2*ind+1);
    make(root->right,v,2*ind+2);
}
void convert(Node *head, TreeNode *&root) {
    vector<int> v;
    while(head){
        v.push_back(head->data);
        head=head->next;
    }
    make(root,v,0);
}