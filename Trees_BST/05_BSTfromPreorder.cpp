#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    int ind=0;
    TreeNode* build(vector<int>&p,unordered_map<int,int>&mp,int l, int r){
        if(l>r) return NULL;
        if(ind==p.size()) return NULL;
        TreeNode*curr = new TreeNode(p[ind]);
        if(l==r) return curr;
        int x = mp[p[ind]];
        int ll = x-1;
        int rr = x+1;
        if(l<=ll){
            ind++;
            curr->left=build(p,mp,l,ll);
        }
        if(rr<=r){
            ind++;
            curr->right=build(p,mp,rr,r);
        }
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mp;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,mp,0,preorder.size()-1);
    }
};