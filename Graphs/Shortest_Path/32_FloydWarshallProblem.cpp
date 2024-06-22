#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void floyd(vector<vector<int>> &adj)
    {
        for (int via = 0; via < adj.size(); via++)
        {
            for (int i = 0; i < adj.size(); i++)
            {
                for (int j = 0; j < adj.size(); j++)
                {
                    if (adj[i][via] != -1 && adj[via][j] != -1)
                    {
                        if (adj[i][j] == -1)
                            adj[i][j] = INT_MAX;
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adj(n, vector<int>(n, -1));
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        floyd(adj);
        int mini = INT_MAX;
        int ans = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            int curr = 0;
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (i != j && adj[i][j] <= distanceThreshold)
                    curr++;
            }
            if (mini >= curr)
            {
                mini = curr;
                ans = i;
            }
        }
        return ans;
    }
};