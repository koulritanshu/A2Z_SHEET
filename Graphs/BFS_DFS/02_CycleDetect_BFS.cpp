#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    bool func(int src, vector<int> adj[], vector<bool> &vis)
    {
        vis[src] = true;
        queue<pair<int, int>> qp;
        qp.push({src, -1});
        while (!qp.empty())
        {
            int cur_node = qp.front().first;
            int cur_parent = qp.front().second;
            qp.pop();
            for (auto &i : adj[cur_node])
            {
                if (vis[i])
                {
                    if (i != cur_parent)
                        return true;
                }
                else
                {
                    vis[i] = true;
                    qp.push({i, cur_node});
                }
            }
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V + 1, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (func(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};