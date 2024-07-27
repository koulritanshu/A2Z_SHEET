// can do using map also

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* tp = st.top();
        int ans = tp->val;
        st.pop();
        if(reverse){
            if(tp->left) tp = tp->left;
            else return ans;
        }
        else{
            if(tp->right) tp = tp->right;
            else return ans;
        }
        while(tp) {
            st.push(tp);
            if(reverse) tp = tp->right;
            else tp = tp->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            int s = i + j;
            if(s==k) return true;
            else if(s>k){
                j = r.next();
            }
            else{
                i = l.next();
            }
        }
        return false;
    }
};