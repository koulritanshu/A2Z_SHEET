#include <bits/stdc++.h>
using namespace std;

class DFS_CYCLE_DETECTION
{
public:
    bool func(vector<vector<int>> &graph, vector<bool> &vis, int curr, vector<bool> &pathVis)
    {
        vis[curr] = true;
        pathVis[curr] = true;
        for (auto &i : graph[curr])
        {
            if (pathVis[i] == true)
                return true;
            else if (vis[i] != true)
            {
                vis[i] = true;
                pathVis[i] = true;
                if (func(graph, vis, i, pathVis))
                    return true;
            }
        }
        pathVis[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto &i : prerequisites)
        {
            int a = i[0];
            int b = i[1];
            graph[a].push_back(b);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (func(graph, vis, i, pathVis))
                {
                    return false;
                }
            }
        }
        return true;
    }
};