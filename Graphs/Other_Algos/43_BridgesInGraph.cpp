#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int curr,int parent,vector<int>&disc, vector<int>&low,vector<int>adj[], vector<bool>&vis, int timer,vector<vector<int>>&result){
        vis[curr] = true;
        disc[curr] = low[curr] = timer++;
        for(auto &i:adj[curr]){
            if(!vis[i] && i!=parent){
                dfs(i,curr,disc,low,adj,vis,timer,result);
                low[curr] = min(low[curr],low[i]);
                if(low[i]>disc[curr]){
                    result.push_back({curr,i});
                }
            }
            else if(i!=parent){
                low[curr] = min(low[curr],low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> discoveryTime(n,-1);
        vector<int> low(n,-1);
        vector<int> adj[n];
        vector<bool> vis(n,false);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        dfs(0,-1,discoveryTime,low,adj,vis,0,ans);
        return ans;
    }
};
