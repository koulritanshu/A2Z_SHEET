#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "?";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* build(vector<string>&v,int &ind){
        if(ind==v.size()) return NULL;
        if(v[ind]=="?") return NULL;
        TreeNode* curr = new TreeNode(stoi(v[ind]));
        ind++;
        curr->left = build(v,ind);
        ind++;
        curr->right = build(v,ind);
        return curr;
    }
    TreeNode* deserialize(string data) {
        vector<string> v;
        string curr = "";
        for(int i=0;i<data.size();i++){
            if(data[i]==' '){
                v.push_back(curr);
                curr="";
            }
            else{
                curr += data[i];
            }
        }
        // for(auto &i:v) cout << i << '$';
        int ind = 0;
        return build(v,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));