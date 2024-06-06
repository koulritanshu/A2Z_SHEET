#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<vector<int>> g(nodes, vector<int>());
    vector<int> indegree(nodes, 0);
    for (int i = 0; i < graph.size(); i++)
    {
        int a = graph[i][0];
        int b = graph[i][1];
        g[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &i : g[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}
