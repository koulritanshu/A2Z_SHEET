#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, int parent, vector<int>&disc,vector<int>&low,vector<bool>&vis,vector<int> adj[], int timer,vector<int>&ap){
        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child=0;
        for(auto &i:adj[node]){
            int nbr = i;
            if(!vis[i]){
                dfs(i,node,disc,low,vis,adj,timer,ap);
                child++;
                low[node] = min(low[node],low[nbr]);
                if(low[nbr]>=disc[node] && parent!=-1){
                    ap[node] = 1;
                }
            }
            else{
                // backedge found
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if(parent==-1&&child>1){
            ap[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> vis(V,false);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<int> ap(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,disc,low,vis,adj,0,ap);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(ap[i]) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};