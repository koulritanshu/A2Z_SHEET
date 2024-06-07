#include <bits/stdc++.h>
using namespace std;

// if it is cyclic, then topological sort does not exist, else exists
// using kahn's algorithm, find topo. sort(BFS) and then just check if it includes all the vertices

class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int v = 0;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            v++;
            for (auto &i : adj[fr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if (v == V)
            return false;
        return true;
    }
};