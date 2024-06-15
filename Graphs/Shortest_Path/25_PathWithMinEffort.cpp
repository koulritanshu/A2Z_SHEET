#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int x1[4] = {1,-1,0,0};
    int y1[4] = {0,0,1,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size()==1 && heights[0].size()==1)return 0;
        vector<vector<int>> ans(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qp;
        qp.push({0,{0,0}});
        while(!qp.empty()){
            int co = qp.top().first;
            int x = qp.top().second.first;
            int y = qp.top().second.second;
            qp.pop();
            if(x==heights.size()-1 && y==heights[0].size()-1) return co;
            for(int k=0;k<4;k++){
                int nx = x + x1[k];
                int ny = y + y1[k];
                if(nx >= 0 && ny >= 0 && nx < heights.size() && ny < heights[0].size() && max(co,(int)abs(heights[nx][ny]-heights[x][y]))<ans[nx][ny]){
                    ans[nx][ny] = max(co,(int)abs(heights[nx][ny]-heights[x][y]));
                    qp.push({ans[nx][ny],{nx,ny}});
                }
            }
        }   
        return ans[heights.size()-1][heights[0].size()-1];
    }
};

// If we are using a priority queue then we can simply return the answer when we are at n-1 and m-1
// Because we can guarantee that on reaching (n-1,m-1) we have the best answer because priority queue
// is in sorted order. If we are using a simple queue, then instead of returning on reaching (n-1,m-1)
// we need to continue as we might a better solution later.