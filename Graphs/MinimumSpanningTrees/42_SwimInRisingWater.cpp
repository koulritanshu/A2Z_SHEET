#include <bits/stdc++.h>
using namespace std;

class Djikstra {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> cost(grid.size(),vector<int>(grid.size(),INT_MAX));
        cost[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({cost[0][0],{0,0}});
        while(!pq.empty()){
            int x1 = pq.top().second.first;
            int y1 = pq.top().second.second;
            int costt = pq.top().first;
            if(x1==grid.size()-1&&y1==grid.size()-1) return costt;
            pq.pop();
            for(int k=0;k<4;k++){
                int nx = x1 + x[k];
                int ny = y1 + y[k];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid.size()){
                    int mxx = max(costt,grid[nx][ny]);
                    if(cost[nx][ny]>mxx){
                        cost[nx][ny] = mxx;
                        pq.push({mxx,{nx,ny}});
                    }
                } 
            }
        }
        return cost[grid.size()-1][grid.size()-1];
    }
};