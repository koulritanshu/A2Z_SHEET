#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int data;
    TreeNode()
    {
        left = right = NULL;
        data = 0;
    }
};
    
class Solution
{
    public:
    void func(TreeNode* root, int x, int y, map<int,pair<int,int>>&mp){
        if(!root) return;
        if(mp.find(x)==mp.end()) mp[x] = {y,root->data};
        else{
            if(mp[x].first > y) mp[x] = {y,root->data};
        }
        func(root->left,x-1,y+1,mp);
        func(root->right,x+1,y+1,mp);
    }
    vector<int> topView(TreeNode *root)
    {
        // for iterative traversal
        // create a map and a queue
        // push levels and value in queue
        // if level does not exist in queue then directly push it into map
        // else do nothing
        // this way height parameter is not required
        map<int,pair<int,int>> mp;
        func(root,0,0,mp);
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second.second);
        }
        return ans;
    }

};