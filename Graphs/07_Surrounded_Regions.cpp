#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        queue<pair<int, int>> qp;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][0] == 'O')
            {
                vis[i][0] = 1;
                qp.push({i, 0});
            }
            if (board[i][board[0].size() - 1] == 'O')
            {
                vis[i][board[0].size() - 1] = 1;
                qp.push({i, board[0].size() - 1});
            }
        }
        for (int i = 1; i < board[0].size() - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                vis[0][i] = 1;
                qp.push({0, i});
            }
            if (board[board.size() - 1][i] == 'O')
            {
                vis[board.size() - 1][i] = 1;
                qp.push({board.size() - 1, i});
            }
        }
        while (!qp.empty())
        {
            int curr_x = qp.front().first;
            int curr_y = qp.front().second;
            qp.pop();
            for (int k = 0; k < 4; k++)
            {
                int nrow = curr_x + delrow[k];
                int ncol = curr_y + delcol[k];
                if (nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
                {
                    vis[nrow][ncol] = 1;
                    qp.push({nrow, ncol});
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != 'X')
                {
                    if (vis[i][j])
                    {
                        board[i][j] = 'O';
                    }
                    else
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};