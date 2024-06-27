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
    int answer(){
        int ans = 0;
        for(int i=0;i<parent.size()-1;i++){
            if(parent[i]==i)
            ans += size[i]-1;
        }
        return ans;
    }
    int answer(map<int,int>&mp){
        int ans = 0;
        for(auto &i:mp){
            if(parent[i.first]==i.first){
                ans++;
            }
        }
        return ans;
    }
};

class Approach1 {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet obj(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(obj.connectedComponents(i,j)) continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    obj.unionBySize(i,j);
                }
            }
        }
        return obj.answer();
    }
};

class Approach2 {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mxRow = -1, mxCol = -1;
        for(auto &i:stones){
            mxRow = max(mxRow,i[0]);
            mxCol = max(mxCol,i[1]);
        }
        DisjointSet ds(mxRow+mxCol+1);
        map<int,int> mp;
        for(int i=0;i<stones.size();i++){
            ds.unionBySize(stones[i][0],stones[i][1]+mxRow+1);
            mp[stones[i][0]]=1;
            mp[stones[i][1]+mxRow+1]=1;
        }
        return stones.size() - ds.answer(mp);
    }
};