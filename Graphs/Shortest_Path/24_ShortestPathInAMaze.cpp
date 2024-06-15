#include <bits/stdc++.h>
using namespace std;

// why DP fails
// https://leetcode.com/problems/shortest-path-in-binary-matrix/solutions/2046009/this-is-why-dp-and-memoization-fail-illustrated-example/

class Solution
{
public:
    int x1[8] = {1, -1, 1, -1, 0, 0, 1, -1};
    int y1[8] = {1, -1, -1, 1, 1, -1, 0, 0};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> qp;
        qp.push({0, 0});
        int level = 1;
        vis[0][0] = true;
        while (!qp.empty())
        {
            int sz = qp.size();
            for (int z = 0; z < sz; z++)
            {
                int x = qp.front().first;
                int y = qp.front().second;
                if (x == grid.size() - 1 && y == grid[0].size() - 1)
                {
                    return level;
                }
                qp.pop();
                for (int k = 0; k < 8; k++)
                {
                    int nx = x + x1[k];
                    int ny = y + y1[k];
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] == 0)
                    {
                        vis[nx][ny] = true;
                        qp.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};