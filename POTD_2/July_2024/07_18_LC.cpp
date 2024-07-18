#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
}; 

class Solution1 {
    // Conversion to a Graph
public:
    void fillMap(TreeNode*curr, TreeNode*par, map<TreeNode*,TreeNode*> &mp,vector<TreeNode*>&leaves){
        if(!curr) return;
        if(!curr->left && !curr->right){
            leaves.push_back(curr);
        }
        if(par){
            mp[curr] = par;
        }
        fillMap(curr->left,curr,mp,leaves);
        fillMap(curr->right,curr,mp,leaves);
    }
    int dfs(TreeNode*root, TreeNode*pre,map<TreeNode*,TreeNode*>&mp, int dist,int curr){
        if(root==NULL) return 0;
        if(curr>dist) return 0;
        if(root->left==NULL && root->right==NULL){
            // cout << root->val << endl;
            return 1;
        }
        int ans = 0;
        if(mp[root] && mp[root]!=NULL && mp[root]!=pre){
            ans = ans + dfs(mp[root],root,mp,dist,curr+1);
        }
        if(root->left && root->left!=pre){
            ans = ans + dfs(root->left,root,mp,dist,curr+1);
        }
        if(root->right && root->right!=pre){
            ans = ans + dfs(root->right,root,mp,dist,curr+1);
        }
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,TreeNode*> reverseConnections;
        vector<TreeNode*> leaves;
        fillMap(root,NULL,reverseConnections,leaves);
        int ans = 0;
        for(int i=0;i<leaves.size();i++){
            // cout << "startingNode = " << leaves[i]->val << endl;
            ans = ans + dfs(reverseConnections[leaves[i]],leaves[i],reverseConnections,distance,1);
        }
        return ans/2;
    }
};


class Solution2 {
    // Optimal
public:
    int ans = 0;
    vector<int> helper(TreeNode*root, int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1};
        vector<int> solveLeft = helper(root->left,d);
        vector<int> solveRight = helper(root->right,d);
        for(auto &i:solveLeft){
            for(auto &j:solveRight){
                if(i+j<=d){
                    ans++;
                }
            }
        }
        vector<int> curr;
        for(auto &i:solveLeft){
            if(i+1<=d) curr.push_back(i+1);
        }
        for(auto &j:solveRight){
            if(j+1<=d) curr.push_back(j+1);
        }
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return ans;
    }   
};