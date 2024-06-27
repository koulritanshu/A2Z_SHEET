#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent,size;
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
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    int generate(int a, int b,int m){
        return a*m + b;
    }
    int largestIsland(vector<vector<int>>& grid) {
        DisjointSet ds(grid.size()*grid[0].size()+1);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nx = i + x[k];
                        int ny = j +y[k];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&& grid[nx][ny]==1){
                            ds.unionBySize(generate(nx,ny,grid[0].size()),generate(i,j,grid[0].size()));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int nx = i + x[k];
                        int ny = j +y[k];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&& grid[nx][ny]==1){
                            st.insert(ds.findUPar(generate(nx,ny,grid[0].size())));
                        }
                    }
                    int sum = 1;
                    for(auto&it:st){
                        sum += ds.size[it];
                    }
                    ans = max(ans,sum);
                }
                else{
                    ans = max(ans,ds.size[generate(i,j,grid[0].size())]);
                }
            }
        }
        return ans;
    }
};