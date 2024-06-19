#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> cost(n+1,INT_MAX);
        cost[start] = 0;
        queue<pair<int,int>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            int no = pq.front().second;
            int co = pq.front().first;
            pq.pop();
            if(no == end) return co;
            for(auto &i:arr){
                int mul = (no*i)%n;
                if(cost[mul]>co+1){
                    cost[mul] = co + 1;
                    pq.push({co+1,mul});
                }
            }
        }
        return -1;
    }
};