#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    Node* targetNode;
    void func(Node* root, map<Node*,Node*>&mp,int target){
        if(!root) return;
        if(root->data==target) targetNode=root;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        func(root->left,mp,target);
        func(root->right,mp,target);
    }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> mp;
        mp[root]=NULL;
        func(root,mp,target);
        int dist = 0;
        queue<Node*> q;
        map<Node*,bool> vis;
        q.push(targetNode);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node* no = q.front();
                q.pop();
                vis[no] = true;
                if(no->left){
                    if(vis[no->left]!=true){
                        q.push(no->left);
                        vis[no->left]=true;
                    }
                }
                if(no->right){
                    if(vis[no->right]!=true){
                        q.push(no->right);
                        vis[no->right]=true;
                    }
                }
                if(mp[no]!=NULL){
                    if(vis[mp[no]]!=true){
                        q.push(mp[no]);
                        vis[mp[no]]=true;
                    }
                }
            }
            dist++;
        }
        return dist-1;
    }
};