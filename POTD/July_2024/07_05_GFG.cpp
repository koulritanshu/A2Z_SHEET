#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

class Solution {
  public:
    void func(Node*root, int &mn, int &mx,int curr){
        if(!root) return;
        mn=min(mn,curr);
        mx=max(mx,curr);
        func(root->left,mn,mx,curr-1);
        func(root->right,mn,mx,curr+1);
    }
    int verticalWidth(Node* root) {
        if(!root) return 0;
        int mn=0,mx=0;
        func(root,mn,mx,0);
        return mx-mn+1;
    }
};