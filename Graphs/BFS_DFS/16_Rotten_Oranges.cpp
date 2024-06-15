#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> qp;
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    qp.push({i, j});
                }
                else if (grid[i][j] == 1)
                    cnt++;
            }
        }
        if (cnt == 0)
            return 0;
        int x1[4] = {0, -1, 1, 0};
        int y1[4] = {1, 0, 0, -1};
        int t = 0;
        while (!qp.empty())
        {
            int size = qp.size();
            for (int x11 = 0; x11 < size; x11++)
            {
                int x = qp.front().first;
                int y = qp.front().second;
                qp.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + x1[k];
                    int ny = y + y1[k];
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        cnt--;
                        qp.push({nx, ny});
                    }
                }
            }
            t++;
        }
        if (cnt > 0)
            return -1;
        return t - 1;
    }
};