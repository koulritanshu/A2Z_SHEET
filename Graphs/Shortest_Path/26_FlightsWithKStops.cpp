#include <bits/stdc++.h>
using namespace std;

// The path this time not only depends on cost but also on k.
// We are going to take a 2D cost vector instead of 1D (first part will be for node and second part will be for k value)

// Lets say if we reach a node x at higher k value than before but this time cost is also more but eventually this path helps
// us in reaching destination at the minimum cost. However, we won't be able to push this cost value into the queue unless we 
// take another parameter for cost through which we check for minimum cost value at the current value of k.

// We can solve in two other ways also:
// a) Priority Queue based on k : This way we won't require a 2D cost vector as based on cost we will get optimal solution
// b) If we are going to use priority queue on k, then we don't even need to use djikstra algo because stops increase by
//    value of 1 which is constant, so we can just use simple BFS.
class PriorityQueueCOST {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];
            adj[a].push_back({b,c});
        }
        // {cost , {k , curr}}
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<k;i++){
            cost[src][i] = 0;
        }
        pq.push({0,{k,src}});
        while(!pq.empty()){
            int co = pq.top().first;
            int kk = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(node == dst) return cost[node][kk];
            for(auto &i:adj[node]){
                int new_d = kk - 1;
                if(i.first==dst) new_d++;
                if(new_d < 0) continue;
                if((co + i.second) < cost[i.first][new_d]){
                    cost[i.first][new_d] = co+i.second;
                    pq.push({co+i.second,{new_d,i.first}});
                }
            } 
        }
        return -1;
    }
};

class BFS
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights,int src, int dst, int K)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        // {stops , {node, cost}}
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};