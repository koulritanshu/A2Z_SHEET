#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
public:
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void func(Node *curr, unordered_map<int,pair<int,int>>&mp){
        if(!curr) return;
        if(mp.find(curr->data)==mp.end()) return;
        curr->left = new Node(mp[curr->data].first);
        func(curr->left,mp);
        if(mp[curr->data].second!=-1){
            curr->right = new Node(mp[curr->data].second);
            func(curr->right,mp);
        }
    }
    Node *createTree(vector<int> par) {
        unordered_map<int,pair<int,int>> mp;
        int root = 0;
        for(int i=0;i<par.size();i++){
            int curr = i;
            int parent = par[i];
            if(parent==-1){
                root = curr;
                continue;
            }
            if(mp.find(parent)==mp.end()){
                mp[parent].first = curr;
                mp[parent].second = -1;
            }
            else if(mp[parent].second==-1){
                mp[parent].second = curr;
            }
            
        }
        Node* ans = new Node(root);
        func(ans,mp);
        return ans;
    }
};