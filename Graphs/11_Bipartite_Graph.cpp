#include <bits/stdc++.h>
using namespace std;

class BRUTE
{
public:
    vector<vector<int>> nodes;
    void func(int se, vector<bool> &vis, int curr, vector<vector<int>> &graph)
    {
        vis[curr] = true;
        nodes[se].push_back(curr);
        for (auto &i : graph[curr])
        {
            if (!vis[i])
            {
                vis[i] = true;
                int temp = ((se == 0) ? 1 : 0);
                func(temp, vis, i, graph);
            }
        }
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        nodes = vector<vector<int>>(2, vector<int>());
        vector<bool> vis(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis[i])
            {
                func(0, vis, i, graph);
            }
        }
        for (int i = 0; i < nodes.size(); i++)
        {
            for (int j = 0; j < nodes[i].size(); j++)
            {
                for (int k = j + 1; k < nodes[i].size(); k++)
                {
                    int a = nodes[i][j];
                    int b = nodes[i][k];
                    if (find(graph[a].begin(), graph[a].end(), b) != graph[a].end())
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

class OPTIMAL
{
public:
    bool dfs(int col, int curr, vector<vector<int>> &graph, vector<int> &color)
    {
        color[curr] = col;
        for (auto &i : graph[curr])
        {
            if (color[i] == -1)
            {
                if (dfs(!col, i, graph, color) == false)
                    return false;
            }
            else if (color[i] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1)
            {
                if (dfs(0, i, graph, color) == false)
                    return false;
            }
        }
        return true;
    }
};