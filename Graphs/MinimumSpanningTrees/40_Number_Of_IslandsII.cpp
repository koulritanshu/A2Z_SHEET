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
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    int generate(int a,int b,int m){
        return a*m + b;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int mx = n*m+1;
        DisjointSet ds(mx+1);
        int cnt = 0;
        vector<vector<int>> curr(n,vector<int>(m,0));
        vector<int> ans;
        for(int i=0;i<operators.size();i++){
            int a = operators[i][0];
            int b = operators[i][1];
            if(curr[a][b]==1){
                ans.push_back(cnt);
                continue;
            }
            curr[a][b] = 1;
            cnt++;
            for(int k=0;k<4;k++){
                int nx = a + x[k];
                int ny = b + y[k];
                if(nx>=0 && ny>=0 && nx<n && ny < m && curr[nx][ny]==1){
                    int first = generate(nx,ny,m);
                    int second = generate(a,b,m);
                    if(!ds.connectedComponents(first,second)){
                        cnt--;
                        ds.unionBySize(first,second);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};