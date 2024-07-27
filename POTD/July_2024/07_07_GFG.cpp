#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

class Solution {
public:
    bool func(vector<int>&v, struct Node*curr, int target){
        if(!curr) return false;
        if(curr->data == target){
            return true;
        }
        v.push_back(curr->data);
        if(func(v,curr->left,target) || func(v,curr->right,target)){
            return true;
        }
        else{
            v.pop_back();
        }
        return false;
    }
    
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        func(ans,root,target);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};