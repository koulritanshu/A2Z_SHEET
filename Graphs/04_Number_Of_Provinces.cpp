#include <bits/stdc++.h>
using namespace std;

// DFS
void func(vector<vector<int>> &roads, int curr_node, vector<bool> &vis)
{
    vis[curr_node] = true;
    for (int i = 0; i < roads.size(); i++)
    {
        if (roads[curr_node][i] == 1)
        {
            if (!vis[i])
            {
                func(roads, i, vis);
            }
        }
    }
}



int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    vector<bool> vis(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != true)
        {
            cnt++;
            func(roads, i, vis);
        }
    }
    return cnt;
}