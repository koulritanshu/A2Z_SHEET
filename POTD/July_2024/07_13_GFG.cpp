#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        int cost[n+1];
        for(int i=0;i<=n;i++) cost[i]=INT_MAX;
        int parent[n+1];
        for(int i=0;i<=n;i++){
            parent[i] = -1;
        }
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        cost[1] = 0;
        parent[1] = -1;
        while(!pq.empty()){
            int node = pq.top().second;
            int costt = pq.top().first;
            pq.pop();
            for(auto &i:adj[node]){
                if(cost[i.first]>costt+i.second){
                    cost[i.first]=costt+i.second;
                    parent[i.first]=node;
                    pq.push({cost[i.first],i.first});
                }
            }
        }
        if(cost[n]==INT_MAX) return {-1};
        vector<int> ans;
        ans.push_back(cost[n]);
        int node = n;
        while(parent[node]!=-1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        return ans;
    }
};