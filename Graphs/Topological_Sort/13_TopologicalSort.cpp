#include <bits/stdc++.h>
using namespace std;

class BRUTE
{
public:
    vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
    {
        vector<int> remainingNodes(nodes, true);
        map<int, vector<int>> mp;
        vector<int> indegree(nodes, 0);
        for (int i = 0; i < graph.size(); i++)
        {
            mp[graph[i][0]].push_back(graph[i][1]);
            indegree[graph[i][1]]++;
        }
        vector<int> ans;
        while (ans.size() != nodes)
        {
            for (int i = 0; i < remainingNodes.size(); i++)
            {
                if (remainingNodes[i] == true)
                {
                    if (indegree[i] == 0)
                    {
                        ans.push_back(i);
                        remainingNodes[i] = false;
                        for (auto &x : mp[i])
                        {
                            indegree[x]--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

class OptimalDFS
{
public:
    void dfs(vector<vector<int>> &graph, int curr, vector<bool> &vis, stack<int> &st)
    {
        vis[curr] = true;
        for (auto &x : graph[curr])
        {
            if (!vis[x])
            {
                vis[x] = true;
                dfs(graph, x, vis, st);
            }
        }
        st.push(curr);
    }

    vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
    {
        vector<bool> vis(nodes, false);
        vector<vector<int>> g(nodes, vector<int>());
        for (int i = 0; i < graph.size(); i++)
        {
            int a = graph[i][0];
            int b = graph[i][1];
            g[a].push_back(b);
        }
        stack<int> st;
        for (int i = 0; i < nodes; i++)
        {
            if (!vis[i])
            {
                dfs(g, i, vis, st);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};