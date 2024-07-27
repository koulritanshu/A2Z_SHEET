#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x){left=right=NULL;}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;
        TreeNode* temp = root;
        while(temp){
            if(temp->left==NULL){
                cnt++;
                if(cnt==k) ans = temp->val;
                temp=temp->right;
            }
            else{
                TreeNode*prev = temp->left;
                while(prev->right && prev->right != temp){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=temp;
                    temp=temp->left;
                }
                else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k) ans = temp->val;
                    temp=temp->right;
                }
            }
        }
        return ans;
    }
};