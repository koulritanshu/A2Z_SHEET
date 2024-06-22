#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        for(int i=0;i<V;i++){
            for(int j=0;j<edges.size();j++){
                int a = edges[j][0];
                int b = edges[j][1];
                int c = edges[j][2];
                if(dist[a]!=INT_MAX && dist[a]+c<dist[b]){
                    dist[b] = dist[a]+c; 
                }
            }
        }
        bool change = false;
        for(int j=0;j<edges.size();j++){
            int a = edges[j][0];
            int b = edges[j][1];
            int c = edges[j][2];
            if(dist[a]!=INT_MAX && dist[a]+c<dist[b]){
                return {-1};
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) dist[i] = 1e8;
        }
        return dist;
    }
};