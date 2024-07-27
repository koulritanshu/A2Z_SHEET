#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution{
public:
    bool func(Node*root){
        if(!root) return true;
        if(!root->left&&!root->right) return true;
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        if(sum!=root->data) return false;
        if(!func(root->left) || !func(root->right)) return false;
        return true;
    }
    int isSumProperty(Node *root)
    {
        return func(root);
    }
};

// Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.
// https://www.naukri.com/code360/problems/childrensumproperty_790723?count=25&page=1&search=&sort_entity=order&sort_order=ASC

void changeTree(Node* root){
    if(!root) return;
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->data <= sum){
        root->data = sum;
    }
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data = tot;
}
