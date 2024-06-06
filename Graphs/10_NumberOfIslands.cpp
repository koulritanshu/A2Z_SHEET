#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
    int y[8] = {1, -1, 1, 0, -1, 1, 0, -1};
    void dfs(vector<vector<bool>> &vis, int i, int j, vector<vector<char>> &grid)
    {
        vis[i][j] = true;
        for (int k = 0; k < 8; k++)
        {
            int nx = i + x[k];
            int ny = j + y[k];
            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1' && vis[nx][ny] == false)
            {
                vis[nx][ny] = true;
                dfs(vis, nx, ny, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    ans++;
                    dfs(vis, i, j, grid);
                }
            }
        }
        return ans;
    }
};