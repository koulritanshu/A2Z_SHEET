#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        else if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    bool connectedComponents(int u, int v)
    {
        return (findUPar(u) == findUPar(v));
    }
    bool check()
    {
        int cnt = 0;
        for (int i = 1; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                cnt++;
            }
        }
        cout << endl;
        return (cnt == 1);
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DisjointSet alice(n);
        DisjointSet bob(n);
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if (type == 3)
            {
                if (!alice.connectedComponents(u, v) && !bob.connectedComponents(u, v))
                {
                    alice.unionBySize(u, v);
                    bob.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if (type == 1)
            {
                if (!alice.connectedComponents(u, v))
                {
                    alice.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if (type == 2)
            {
                if (!bob.connectedComponents(u, v))
                {
                    bob.unionBySize(u, v);
                }
                else
                {
                    cnt++;
                }
            }
        }
        if (!alice.check() || !bob.check())
            return -1;
        return cnt;
    }
};