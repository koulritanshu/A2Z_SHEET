#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node()
    {
        left = right = NULL;
        val = 0;
    }
};

void addLeft(vector<int>&ans, Node*root){
    if(!root) return;
    Node*start = root;
    while(root->left || root->right){
        ans.push_back(root->val);
        if(root->left) root = root->left;
        else if(root->right) root = root->right;
    }
}

void addRight(vector<int>&ans,Node*root){
    if(!root) return;
    stack<int> st;
    while(root->left||root->right){
        if(!root) break;
        st.push(root->val);
        if(root->right) root = root->right;
        else if(root->left) root = root->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

void addLeaves(vector<int>&ans, Node*root){
    if(!root)return;
    addLeaves(ans,root->left);
    if(root && !root->left&&!root->right) ans.push_back(root->val);
    addLeaves(ans,root->right);
}

vector<int> traverseBoundary(Node *root)
{
	// Write your code here.
    if(!root->left&&!root->right)return {root->val};
    Node*temp = root;
    vector<int> ans;
    ans.push_back(root->val);
    addLeft(ans,temp->left);
    addLeaves(ans,temp);
    addRight(ans,temp->right);
    return ans;
}