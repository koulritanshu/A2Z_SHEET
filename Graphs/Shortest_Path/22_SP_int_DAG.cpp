#include <bits/stdc++.h>
using namespace std;

// As there are no cycles, we can use topological sort.

class Solution {
public:
    void dfs(vector<bool>&vis, stack<int>&st, int curr, vector<pair<int,int>>adj[]){
        vis[curr] = true;
        for(auto &i:adj[curr]){
            if(!vis[i.first]){
                dfs(vis,st,i.first,adj);
            }
        }
        st.push(curr);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int>st;
        vector<bool>vis(N,false);
        vector<pair<int,int>> adj[N];
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b,c});
        }
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(vis,st,i,adj);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        vector<int> ans(N,INT_MAX);
        ans[0] = 0;
        // can pop simply from stack without needing to create topo vector
        for(int i=0;i<topo.size();i++){
            int curr = topo[i];
            int cost = ans[curr];
            if(cost==INT_MAX) continue;
            for(auto &j:adj[curr]){
                if(ans[j.first]>(j.second+cost)){
                    ans[j.first]=j.second+cost;
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};