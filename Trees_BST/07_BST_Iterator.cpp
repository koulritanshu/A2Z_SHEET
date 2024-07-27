#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* tp = st.top();
        int ans = tp->val;
        st.pop();
        if(tp->right) tp = tp->right;
        else return ans;
        while(tp) {
            st.push(tp);
            tp = tp->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};