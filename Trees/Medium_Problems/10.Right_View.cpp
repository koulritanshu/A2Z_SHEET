#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
};

class Solution {
public:
    void func(TreeNode* root, map<int,int>&mp,int y){
        if(!root) return;
        if(mp.find(y)==mp.end())
        mp[y] = root->val;
        func(root->right,mp,y+1);
        func(root->left,mp,y+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        func(root,mp,0);
        vector<int> ans;
        for(auto &i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};