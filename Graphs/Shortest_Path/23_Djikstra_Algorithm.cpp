#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        pq.push({0, S});
        vector<bool> vis(V, false);
        while (!pq.empty())
        {
            int fr = pq.top().second;
            int co = pq.top().first;
            vis[fr] = true;
            ans[fr] = min(ans[fr], co);
            pq.pop();
            for (auto &i : adj[fr])
            {
                if (!vis[i[0]]) 
                {
                    pq.push({i[1] + co, i[0]});
                }
            }
        }
        return ans;
    }
};