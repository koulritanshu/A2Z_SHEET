#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

class Solution {
  public:
    void trav(Node*curr,string &s){
        if(curr){
            s += to_string(curr->data)+' ';
        }
        else{
            s += "?";
            return;
        }
        trav(curr->left,s);
        trav(curr->right,s);
    }
    void func(vector<Node*> &ans, Node*root,unordered_map<string,int>&mp){
        if(!root) return;
        string x="";
        trav(root,x);
        // cout << "x = " << x << endl;
        if(mp[x]==1){
            ans.push_back(root);
            mp[x]=2;
        }else{
            if(mp[x]!=2) mp[x]=1;
        }
        func(ans,root->left,mp);
        func(ans,root->right,mp);
    }
    vector<Node*> printAllDups(Node* root) {
        vector<Node*> ans;
        unordered_map<string,int>mp;
        func(ans,root->left,mp);
        func(ans,root->right,mp);
        return ans;
    }
};