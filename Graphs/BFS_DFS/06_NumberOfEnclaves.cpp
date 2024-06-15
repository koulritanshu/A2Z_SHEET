#include <bits/stdc++.h>
using namespace std;

class Brute
{
public:
    void func(vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<vector<int>> &v, int i, int j)
    {
        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        vis[i][j] = true;
        v[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && vis[nrow][ncol] != true && grid[nrow][ncol] == 1)
            {
                v[nrow][ncol] = 1;
                vis[nrow][ncol] = true;
                func(grid, vis, v, nrow, ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0] == 1)
            {
                vis[i][0] = true;
                v[i][0] = 1;
                func(grid, vis, v, i, 0);
            }
            if (grid[i][grid[0].size() - 1] == 1)
            {
                vis[i][grid[i].size() - 1] = true;
                v[i][grid[i].size() - 1] = 1;
                func(grid, vis, v, i, grid[0].size() - 1);
            }
        }
        for (int j = 1; j < grid[0].size() - 1; j++)
        {
            if (grid[0][j] == 1)
            {
                vis[0][j] = true;
                v[0][j] = 1;
                func(grid, vis, v, 0, j);
            }
            if (grid[grid.size() - 1][j] == 1)
            {
                vis[grid.size() - 1][j] = true;
                v[grid.size() - 1][j] = 1;
                func(grid, vis, v, grid.size() - 1, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && v[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

class MultiSourceBFS
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> qp;
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0] == 1)
            {
                vis[i][0] = 1;
                qp.push({i, 0});
            }
            if (grid[i][grid[0].size() - 1] == 1)
            {
                vis[i][grid[i].size() - 1] = 1;
                qp.push({i, grid[0].size() - 1});
            }
        }
        for (int j = 1; j < grid[0].size() - 1; j++)
        {
            if (grid[0][j] == 1)
            {
                vis[0][j] = 1;
                qp.push({0, j});
            }
            if (grid[grid.size() - 1][j] == 1)
            {
                vis[grid.size() - 1][j] = 1;
                qp.push({grid.size() - 1, j});
            }
        }
        int cnt = 0;
        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        while (!qp.empty())
        {
            int x = qp.front().first;
            int y = qp.front().second;
            qp.pop();
            cnt++;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + delrow[k];
                int ny = y + delcol[k];
                if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1 && vis[nx][ny] == 0)
                {
                    vis[nx][ny] = 1;
                    qp.push({nx, ny});
                }
            }
        }
        int x1 = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    x1++;
            }
        }
        return max(0, x1 - cnt);
    }
};
