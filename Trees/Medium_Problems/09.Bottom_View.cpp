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

// only difference is we will use <= x instead of < x (Reason: two nodes can have same x and y)

class Solution {
  public:
    void func(map<int,pair<int,int>>&mp, TreeNode*root, int level, int x){
        if(!root) return;
        if(mp.find(level)==mp.end()) mp[level] = {x,root->data};
        else{
            if(mp[level].first <= x){
                mp[level] = {x,root->data};
            }
        }
        func(mp,root->left,level-1,x+1);
        func(mp,root->right,level+1,x+1);
    }
    vector <int> bottomView(TreeNode *root) {
        map<int,pair<int,int>> mp;
        func(mp,root,0,0);
        vector<int> ans;
        for(auto i:mp){
            ans.push_back((i.second).second);
        }
        return ans;
    }
    vector<int> bottomView(){
        // for iterative traversal
        // create a map and a queue
        // push levels and value in queue
        // if level does not exist in queue then directly push it into map
        // else replace the element in map to the current one in queue
        // this way height parameter is not required
    }
};

class BFS {
public:

    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        mp[0] = root->data;
        while(!q.empty()){
            Node* fr = q.front().first;
            int co = q.front().second;
            q.pop();
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