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

class Solution {
public:
    TreeNode* LCA(TreeNode*root, int start, int end){
        if(!root||root->val==start||root->val==end) return root;
        TreeNode*left = LCA(root->left,start,end);
        TreeNode*right = LCA(root->right,start,end);
        if(!left) return right;
        else if(!right) return left;
        else {
            return root;
        }
    }
    bool path(string &p, TreeNode*curr, int fin){
        if(!curr) return false;
        if(curr->val==fin){
            return true;
        }
        p += 'L';
        if(path(p,curr->left,fin)){
            return true;
        }
        else{
            p.pop_back();
            p += 'R';
            if(path(p,curr->right,fin)){
                return true;
            }
            else{
                p.pop_back();
                return false;
            }
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root,startValue,destValue);
        string left="";
        string right="";
        path(left,lca,startValue);
        path(right,lca,destValue);
        for(int i=0;i<left.size();i++){
            left[i]='U';
        }
        string ans = left + right;
        return ans;
    }
};