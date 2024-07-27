#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x)
    {
        left = right = NULL;
        val = x;
    }    
};

bool func(vector<int>&ans, TreeNode* curr,int target){
    if(!curr) return false;
    if(curr->val==target){
        ans.push_back(curr->val);
        return true;
    }
    ans.push_back(curr->val);
    if(func(ans,curr->left,target)||func(ans,curr->right,target)){
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> path(TreeNode*root,int target){
    vector<int> ans;
    func(ans,root,target);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    vector<int> ans = path(root,7);
    for(auto &i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}