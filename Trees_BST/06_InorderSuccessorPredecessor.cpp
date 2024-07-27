#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

int inorderSucessor(TreeNode* root,int target){
    int ans = INT_MAX;
    while(root){
        if(root->val > target){
            ans = min(ans,root->val);
            root = root->left;
        }
        else if(root->val <= target){
            root=root->right;
        }
    }
    if(ans==INT_MAX) cout << "Successor does not exist\n";
    return ans;
}

int inorderPredecessor(TreeNode* root,int target){
    int ans = INT_MAX;
    while(root){
        if(root->val >= target){
            root = root->left;
        }
        else if(root->val < target){
            ans = max(ans,root->val);
            root=root->right;
        }
    }
    if(ans==INT_MAX) cout << "Predecessor does not exist\n";
    return ans;
}

int main()
{
    return 0;
}