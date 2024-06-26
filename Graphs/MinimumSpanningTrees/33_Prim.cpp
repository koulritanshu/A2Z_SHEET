#include <bits/stdc++.h>
using namespace std;


// Time Complexity - O(E log E) 
// Space Complexity -   
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int ans = 0;
        vector<bool> vis(V, false);
        while (!pq.empty())
        {
            int no = pq.top().second;
            int co = pq.top().first;
            pq.pop();
            if (vis[no])
                continue;
            vis[no] = true;
            ans += co;
            for (auto &i : adj[no])
            {
                if (!vis[i[0]])
                {
                    pq.push({i[1], i[0]});
                }
            }
        }
        return ans;
    }
};