#include <bits/stdc++.h>
using namespace std;

// T.C = O(N + 2*E)
// S.C = O(N)

// 1. Since the graph is weightless, we can use BFS
// 2. BFS will work based on how distant a node is from the source vertex
// 3. In the case of a weighted graph, we will need to adjust our algorithm according to the weights
class BFS
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<pair<int, int>> qp;
        qp.push({src, 0});
        vector<int> ans(N, INT_MAX);
        vector<bool> vis(N, false);
        while (!qp.empty())
        {
            int node = qp.front().first;
            int cost = qp.front().second;
            qp.pop();
            vis[node] = true;
            ans[node] = min(ans[node], cost);
            for (auto &i : adj[node])
            {
                if (!vis[i])
                {
                    qp.push({i, cost + 1});
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};