#include <bits/stdc++.h>
using namespace std;

// we will use the concept of a path visited vector also
// only if the node is already visited in the same path, then only we can say 
// that there is a cycle

bool func(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathvis, int curr)
{
    vis[curr] = true;
    pathvis[curr] = true;
    for (auto &i : graph[curr])
    {
        if (pathvis[i] == true)
        {
            return true;
        }
        else if (vis[i] != true && func(graph, vis, pathvis, i))
        {
            return true;
        }
    }
    pathvis[curr] = false;
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    vector<bool> vis(v, false);
    vector<bool> pathvis(v, false);
    vector<vector<int>> graph(v, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a].push_back(b);
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (func(graph, vis, pathvis, i))
            {
                return true;
            }
        }
    }
    return false;
}
