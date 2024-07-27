#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        if(!root) return false; 
        if(target==root->data && !root->left && !root->right) return true;
        int x = target-root->data;
        return hasPathSum(root->left,x)||hasPathSum(root->right,x);
    }
};