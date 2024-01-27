#include <bits/stdc++.h>
using namespace std;

template<class T>
class TreeNode
{
public:
    TreeNode <T>*left;
    TreeNode <T>*right;
    T data;
    TreeNode()
    {
        left = right = NULL;
        val = 0;
    }
};

void addLeft(vector<int>&ans, TreeNode<int>*root){
    if(!root) return;
    TreeNode<int>*start = root;
    while(root->left || root->right){
        ans.push_back(root->data);
        if(root->left) root = root->left;
        else if(root->right) root = root->right;
    }
}

void addRight(vector<int>&ans,TreeNode<int>*root){
    if(!root) return;
    stack<int> st;
    while(root->left||root->right){
        if(!root) break;
        st.push(root->data);
        if(root->right) root = root->right;
        else if(root->left) root = root->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

void addLeaves(vector<int>&ans, TreeNode<int>*root){
    if(!root)return;
    addLeaves(ans,root->left);
    if(root && !root->left&&!root->right) ans.push_back(root->data);
    addLeaves(ans,root->right);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    TreeNode<int>*temp = root;
    vector<int> ans;
    ans.push_back(root->data);
    addLeft(ans,temp->left);
    addLeaves(ans,temp);
    addRight(ans,temp->right);
    return ans;
}