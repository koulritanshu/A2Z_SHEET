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

class CYCLE_USING_BFS
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree[i])
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            cnt++;
            for (auto &i : graph[fr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return (cnt == numCourses);
    }
};