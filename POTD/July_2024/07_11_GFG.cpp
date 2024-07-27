#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
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
};

class Solution {
  public:
    int arr[5] = {1,0,-1,0,1};
    int f(int r,int c, int m){
        return r*m + c;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int m = grid[0].size();
        DisjointSet obj(grid.size()*grid[0].size());
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nx = i+arr[k];
                        int ny = j+arr[k+1];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&grid[nx][ny]){
                            obj.unionBySize(f(nx,ny,m),f(i,j,m));
                        }
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int nx = i+arr[k];
                        int ny = j+arr[k+1];
                        if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&grid[nx][ny]){
                            st.insert(obj.findUPar(f(nx,ny,m)));
                        }
                    }
                    int curr=1;
                    for(auto &i:st){
                        curr+=obj.size[i];
                    }
                    ans=max(ans,curr);
                }
                else{
                    int par = obj.findUPar(f(i,j,m));
                    ans=max(ans,obj.size[par]);
                }
            }
        }
        return ans;
    }
};