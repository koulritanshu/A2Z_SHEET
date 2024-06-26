#include <bits/stdc++.h>
using namespace std;

class DisjointRank{
    vector<int> rank,parent;
public:
    DisjointRank(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        parent[node] = findUPar(parent[node]); 
    }
    bool connectedComponents(int u, int v){
        return (findUPar(u)==findUPar(v));
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u; 
        }
        else{
            rank[ulp_u]++;
            parent[ulp_v] = ulp_u;
        }
    }
};