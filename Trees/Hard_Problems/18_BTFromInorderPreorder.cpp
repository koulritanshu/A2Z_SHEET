#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

class Solution {
public:
    int ind = 0;
    TreeNode* build(vector<int>&p,unordered_map<int,int>&mp,  int l, int r){
        if(ind==p.size()) return NULL;
        TreeNode*curr = new TreeNode(p[ind]);
        if(l==r) return curr;
        else{
            int x = mp[p[ind]];
            int ll = x-1;
            if(l<=ll) {
                ind++;
                curr->left=build(p,mp,l,ll);
            }
            int rr = x+1;
            if(r>=rr) {
                ind++;
                curr->right=build(p,mp,rr,r);
            }
        }
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,mp,0,preorder.size()-1);
    }
};