#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
public:
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> mpp;
        for(int i=0;i<descriptions.size();i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            TreeNode* par;
            TreeNode*chi;
            if(mp[parent]!=nullptr){
                par=mp[parent];
            }
            else{
                par=new TreeNode(parent);
                par->left=NULL;
                par->right=NULL;
                mp[parent]=par;
            }
            if(mp[child]!=nullptr){
                chi=mp[child];
            }
            else{
                chi=new TreeNode(child);
                chi->left=NULL;
                chi->right=NULL;
                mp[child]=chi;
            }
            if(isLeft){
                par->left=chi;
            }
            else{
                par->right=chi;
            }
            mpp[child]=true;
        }
        for(auto &i:descriptions){
            if(mpp[i[0]]!=true){
                return mp[i[0]];
            }
        }
        return NULL;
    }
};