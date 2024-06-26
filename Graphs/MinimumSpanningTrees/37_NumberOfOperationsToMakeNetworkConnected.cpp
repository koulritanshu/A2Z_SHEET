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
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
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
    int similar(){
        int cnt = 0;
        for(int i=0;i<parent.size()-1;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<(n-1)) return -1;
        DisjointSet obj(n);
        int extra = 0;
        for(int i=0;i<connections.size();i++){
            if(obj.connectedComponents(connections[i][0],connections[i][1])){
                extra++;
            }
            else{
                obj.unionBySize(connections[i][0],connections[i][1]);
            }
        }
        int required = obj.similar()-1;
        if(extra >= required){
            return required;
        }
        else{
            return -1;
        }
    }
};