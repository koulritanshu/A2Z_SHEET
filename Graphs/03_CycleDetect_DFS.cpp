#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    bool func(vector<int> adj[], int curr_node, int parent_node, vector<bool> &vis)
    {
        vis[curr_node] = true;
        for (auto &i : adj[curr_node])
        {
            if (vis[i] == true)
            {
                if (parent_node != i)
                    return true;
            }
            else
            {
                if (func(adj, i, curr_node, vis))
                    return true;
            }
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (func(adj, i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};