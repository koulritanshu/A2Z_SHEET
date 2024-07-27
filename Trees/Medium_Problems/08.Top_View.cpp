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
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node()
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
        map<int,pair<int,int>> mp;
        func(root,0,0,mp);
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second.second);
        }
        return ans;
    }

};

class BFS
{
public:
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        mp[0] = root->data;
        while(!q.empty()){
            Node* fr = q.front().first;
            int co = q.front().second;
            q.pop();
            if(mp.find(co)==mp.end())
            mp[co] = fr->data;
            if(fr->left){
                q.push({fr->left,co-1});
            }
            if(fr->right){
                q.push({fr->right,co+1});
            }
        }
        vector<int> ans;
        for(auto &i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }

};