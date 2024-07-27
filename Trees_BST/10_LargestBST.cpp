#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class NodeValue{
public:
    int mini,maxi,size;
    NodeValue(int a, int b, int c){
        mini = a;
        maxi = b;
        size = c;
    }
};

class Solution{
public:
    NodeValue func(Node* root){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0);
        auto left = func(root->left);
        auto right = func(root->right);
        if(root->data > left.maxi && root->data < right.mini){
            return NodeValue(min(root->data,left.mini),max(root->data,right.maxi),right.size+left.size+1);
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
    }
    int largestBst(Node *root)
    {
        return func(root).size;
    }
};