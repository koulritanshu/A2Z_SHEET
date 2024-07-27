#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        map<int,vector<int>> mp;
        for(int i=0;i<profits.size();i++){
            mp[capital[i]].push_back(profits[i]);
        }
        priority_queue<int,vector<int>> pq;
        map<int,vector<int>>::iterator it = mp.begin();
        while(it!=mp.end() && it->first <= w){
            for(auto &x:it->second) pq.push(x);
            ++it;
        }
        int cnt = 0;
        int cap = w;
        int pro = 0;
        while(cnt!=k&&!pq.empty()){
            int proo = pq.top();
            pq.pop();
            pro += proo;
            cap += proo;
            while(it!=mp.end() && it->first <= cap){
                for(auto &x:it->second) pq.push(x);
                ++it;
            } 
            cnt++;
        }
        return cap;
    }
};