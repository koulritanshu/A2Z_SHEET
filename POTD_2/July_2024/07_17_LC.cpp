#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
public:
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

class Solution{
public:
    void func(TreeNode* curr, TreeNode* parent, unordered_map<int,bool>&d,  vector<TreeNode*> &ans){
        if(!curr) return;
        if(d[curr->val]==true){
            func(curr->left,NULL,d,ans);
            func(curr->right,NULL,d,ans);
            return;
        }
        if(curr && parent==NULL){
            ans.push_back(curr);
        }
        if(curr->left && d[curr->left->val] == true){
            TreeNode*change = curr->left;
            curr->left = NULL;
            if(change->left){
                func(change->left,NULL,d,ans);
            }
            if(change->right){
                func(change->right,NULL,d,ans);
            }
        }
        else if(curr->left){
            func(curr->left,curr,d,ans);
        }
        if(curr->right && d[curr->right->val] == true){
            TreeNode*change = curr->right;
            curr->right = NULL;
            if(change->left){
                func(change->left,NULL,d,ans);
            }
            if(change->right){
                func(change->right,NULL,d,ans);
            }
        }
        else if(curr->right){
            func(curr->right,curr,d,ans);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int,bool> d;
        for(auto &i:to_delete){
            d[i] = true;
        }
        func(root,NULL,d,ans);
        return ans;
    }
};