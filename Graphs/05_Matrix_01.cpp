#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> v(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> qp;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    qp.push({{i, j}, 0});
                }
            }
        }
        while (!qp.empty())
        {
            int i = qp.front().first.first;
            int j = qp.front().first.second;
            int dist = qp.front().second;
            qp.pop();
            vis[i][j] = 1;
            v[i][j] = min(v[i][j], dist);
            if (i + 1 < mat.size())
            {
                if (vis[i + 1][j] != 1 && mat[i + 1][j] != 0)
                {
                    qp.push({{i + 1, j}, dist + 1});
                }
            }
            if (j + 1 < mat[0].size())
            {
                if (vis[i][j + 1] != 1 && mat[i][j + 1] != 0)
                {
                    qp.push({{i, j + 1}, dist + 1});
                }
            }
            if (i - 1 >= 0)
            {
                if (vis[i - 1][j] != 1 && mat[i - 1][j] != 0)
                {
                    qp.push({{i - 1, j}, dist + 1});
                }
            }
            if (j - 1 >= 0)
            {
                if (vis[i][j - 1] != 1 && mat[i][j - 1] != 0)
                {
                    qp.push({{i, j - 1}, dist + 1});
                }
            }
        }
        return v;
    }
};

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> v(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> qp;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    qp.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, -1, 0, 1};
        while (!qp.empty())
        {
            int i = qp.front().first.first;
            int j = qp.front().first.second;
            int dist = qp.front().second;
            qp.pop();
            v[i][j] = dist;
            for (int k = 0; k < 4; k++)
            {
                int nr = i + nrow[k];
                int nc = j + ncol[k];
                if (nr >= 0 && nr < mat.size() && nc >= 0 && nc < mat[0].size() && vis[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    qp.push({{nr, nc}, dist + 1});
                }
            }
        }
        return v;
    }
};