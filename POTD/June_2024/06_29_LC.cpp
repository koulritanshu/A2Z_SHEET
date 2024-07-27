#include <bits/stdc++.h>
using namespace std;

class TopologicalSort {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> topo;
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>> ans(n);
        vector<set<int>> ansset(n);
        queue<int> kahn;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                kahn.push(i);
            }
        }
        while(!kahn.empty()){
            int no = kahn.front();
            kahn.pop();
            topo.push_back(no);
            for(auto &i:adj[no]){
                indegree[i]--;
                if(indegree[i]==0){
                    kahn.push(i);
                }
            }
        }
        for(int i=0;i<topo.size();i++){
            int node = topo[i];
            for(auto &x:adj[node]){
                ansset[x].insert(node);
                ansset[x].insert(ansset[node].begin(),ansset[node].end());
            }
        }
        for(int i=0;i<n;i++){
            ans[i].assign(ansset[i].begin(),ansset[i].end());
            // sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};

class Solution {
public:
    // DFS after edge reversal of the graph
    // TC - O(n*n + n*m)
    // SC - O(n*n + m)
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void dfs(int curr, vector<vector<int>>&ans, vector<bool>&vis,vector<int> adj[]){
        vis[curr] = true;
        set<int> st;
        for(auto &i:adj[curr]){
            st.insert(i);
            if(vis[i]){
                for(auto &x:ans[i]){
                    st.insert(x);
                }
            }
            else{
                dfs(i,ans,vis,adj);
                for(auto &x:ans[i]){
                    st.insert(x);
                }
            }
        }
        for(auto &x:st){
            ans[curr].push_back(x);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> ans(n,vector<int>());
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,ans,vis,adj);
            }
        }
        return ans;
    }
};