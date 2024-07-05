#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
public:
    Node*pre;
    void inorder(Node*root){
        if(!root) return;
        inorder(root->left);
        if(pre){
            pre->next=root;
            pre=root;
        }
        else{
            pre=root;
        }
        inorder(root->right);
    }
    void populateNext(Node *root) {
        pre=NULL;
        inorder(root);
    }
};