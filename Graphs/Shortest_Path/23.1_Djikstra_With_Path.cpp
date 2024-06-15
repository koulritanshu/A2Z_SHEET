// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

// Note -
// 1. If there exists a path, then return a list whose first element is the weight of the path.
// 2. If no path exists then return a list containing a single element -1.

// Example:
// Input:
// n = 5, m= 6
// edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
// Output:
// 5 1 4 3 5
// Explaination:
// Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(n + 1, INT_MAX);
        vector<int> parent(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        pq.push({0, 1});
        parent[1] = 0;
        ans[1] = 0;
        while (!pq.empty())
        {
            int co = pq.top().first;
            int no = pq.top().second;
            pq.pop();
            for (auto &i : adj[no])
            {
                if (co + i.second < ans[i.first])
                {
                    ans[i.first] = co + i.second;
                    parent[i.first] = no;
                    pq.push({co + i.second, i.first});
                }
            }
        }
        if (ans[n] == INT_MAX)
            return {-1};
        vector<int> path;
        path.push_back(n);
        int curr = n;
        while (parent[curr] != 0)
        {
            path.push_back(parent[curr]);
            curr = parent[curr];
        }
        path.push_back(ans[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};