#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &p)
    {
        vector<int> answer;
        map<int, vector<int>> graph;
        queue<int> q;
        vector<int> indegree(n, 0);
        for (int i = 0; i < p.size(); i++)
        {
            graph[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }
        for (int i = 0; i < n; i++)
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
            answer.push_back(fr);
            for (auto &i : graph[fr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if (answer.size() != n)
            return {};
        return answer;
    }
};