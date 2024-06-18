#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj[a].push_back({b,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> cost(n+1,INT_MAX);
        cost[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int no = pq.top().second;
            int co = pq.top().first;
            pq.pop();
            for(auto &i:adj[no]){
                int adjN = i.first;
                int edW = i.second;
                if(co + edW < cost[adjN]){
                    cost[adjN] = co + edW;
                    pq.push({co+edW,adjN});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(cost[i]==INT_MAX) return -1;
            ans = max(ans,cost[i]);
        }
        return ans;
    }
};