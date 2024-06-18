#include <bits/stdc++.h>
using namespace std;

class Optimal {
public:
    long mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
        vector<pair<long,long>> adj[n];
        for(auto &i :roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<long> cost(n,LONG_MAX);
        vector<long> ways(n,0);
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long no = pq.top().second;
            long co = pq.top().first;
            pq.pop();
            if(no == (n-1)){
                continue;
            }
            for(auto &i:adj[no]){
                if(i.second + co < cost[i.first]){
                    ways[i.first] = ways[no]%mod;
                    cost[i.first] = i.second+co;
                    pq.push({cost[i.first],i.first});
                }
                else if(i.second+co==cost[i.first]){
                    ways[i.first] = (ways[i.first]+ways[no]%mod)%mod;
                }
            }
        }
        return (int)ways[n-1]%mod;
    }
};

class BruteForce {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> adj[n];
        for(auto &i :roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> cost(n,INT_MAX);
        int ans = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int no = pq.top().second;
            int co = pq.top().first;
            pq.pop();
            if(no == n-1) continue;
            for(auto &i:adj[no]){
                if(i.second + co <= cost[i.first]){
                    pq.push({i.second+co,i.first});
                    if(i.first == (n-1)){
                        if(i.second+co==cost[i.first]){
                            ans = (ans%mod+1)%mod;
                        }
                        else{
                            ans = 1;
                        }
                    }
                    cost[i.first] = i.second+co;
                }
            }
        }
        return ans;
    }
};