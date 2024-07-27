#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};

class Better {
public:
    string func(vector<TreeNode*> &ans, TreeNode*root,unordered_map<string,int>&mp){
        if(!root) return "? ";
        string leftt = func(ans,root->left,mp);
        string rightt = func(ans,root->right,mp);
        string curr = to_string(root->val) + ' ' + leftt + rightt;
        if(mp[curr]==1){
            ans.push_back(root);
            mp[curr]=2;
        }else{
            if(mp[curr]!=2) mp[curr]=1;
        }
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int>mp;
        func(ans,root->left,mp);
        func(ans,root->right,mp);
        return ans;
    } 
};

class Brute {
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