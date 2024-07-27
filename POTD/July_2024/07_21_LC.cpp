#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topo(vector<vector<int>> &adj){
        vector<int> indegree(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        vector<int>v;
        for(int i=1;i<adj.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            v.push_back(node);
            for(auto &i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        int x=0;
        for(int i=0;i<indegree.size();i++) if(indegree[i])x++;
        if(x==0) return v;
        return {};
    }
    void fillVector(vector<int>&a, int k){
        unordered_map<int,bool> mp;
        for(auto &i:a) mp[i]=true;
        for(int i=1;i<=k;i++){
            if(!mp[i]) a.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<vector<int>> adjRow(k+1);
        vector<vector<int>> adjCol(k+1);
        for(int i=0;i<r.size();i++){
            adjRow[r[i][0]].push_back(r[i][1]);
        }
        vector<int> toporow = topo(adjRow);
        if(toporow.size()==0) return {};
        for(int i=0;i<c.size();i++){
            adjCol[c[i][0]].push_back(c[i][1]);
        }
        vector<int> topocol = topo(adjCol);
        if(topocol.size()==0) return {};
        fillVector(toporow,k);
        fillVector(topocol,k);
        vector<pair<int,int>> vp(k+1,{-1,-1});
        for(int i=0;i<toporow.size();i++){
            vp[toporow[i]].first=i;
            vp[topocol[i]].second=i;
        }
        for(int i=1;i<vp.size();i++){
            ans[vp[i].first][vp[i].second]=i;
        }
        return ans;
    }
};