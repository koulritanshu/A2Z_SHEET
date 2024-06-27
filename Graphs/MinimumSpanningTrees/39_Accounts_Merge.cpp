#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    bool connectedComponents(int u, int v){
        return (findUPar(u)==findUPar(v));
    }
};

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<string> adj[accounts.size()];
        for(auto &i:mp){
            string email = i.first;
            int index = ds.findUPar(i.second);
            adj[index].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            if(adj[i].size()==0) continue;
            sort(adj[i].begin(),adj[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &ix:adj[i]) temp.push_back(ix);
            ans.push_back(temp);
        }
        return ans;
    }
};