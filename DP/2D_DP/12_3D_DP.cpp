#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp1(m+1,vector<int>(m+1,0));
        vector<vector<int>> dp2(m+1,vector<int>(m+1,0));
        dp2[0][m-1] = grid[0][0] + grid[0][m-1]; 
        int ans = 0;
        for(int row=0;row<n;row++){
            for(int col1=0;col1<=row&&col1<m;col1++){
                for(int col2=m-1;col2>=0&&col2>=m-1-row;col2--){
                    int curr = grid[row][col1] + ((col1!=col2)?grid[row][col2]:0);
                    int upper = 0;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            int _col1 = i+col1;
                            int _col2 = j+col2;
                            if(row > 0 && _col1 >= 0 && _col2 >= 0 && _col1 < m && _col2 < m && _col1<=row && _col2 >= m-1-row){
                                upper = max(upper,dp1[_col1][_col2]);
                            }
                        }
                    }
                    dp2[col1][col2] = curr+upper;
                    ans = max(ans,dp2[col1][col2]);
                }
            }
            dp1 = dp2;
        }
        return ans;
    }
};

class BottomUp
{
    // Tabulation
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        int ans = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col1 = 0; col1 <= row && col1 < m; col1++)
            {
                for (int col2 = m - 1; col2 >= m - 1 - row && col2 >= 0; col2--)
                {
                    int curr = grid[row][col1] + ((col1 != col2) ? grid[row][col2] : 0);
                    dp[row][col1][col2] = curr;
                    int maxi = 0;
                    for (int i = -1; i <= 1; i++)
                    {
                        for (int j = -1; j <= 1; j++)
                        {
                            int _col1 = col1 + i;
                            int _col2 = col2 + j;
                            if (_col1 >= 0 && _col2 >= 0 && _col1 < m && _col2 < m && row > 0)
                            {
                                int upper = dp[row - 1][_col1][_col2];
                                maxi = max(maxi, upper);
                            }
                        }
                    }
                    dp[row][col1][col2] += maxi;
                    ans = max(ans, dp[row][col1][col2]);
                }
            }
        }
        return ans;
    }
};

class TopDown
{
    // Memoization
public:
    int dp[71][71][71];
    int func(vector<vector<int>> &grid, int row, int col1, int col2)
    {
        if (row >= grid.size() || col1 >= grid[0].size() || col2 >= grid[0].size() || col2 < 0 || col1 < 0)
            return 0;
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int ans1 = grid[row][col1];
        ans1 += (col1 != col2) ? grid[row][col2] : 0;
        int ans = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                ans = max(ans, func(grid, row + 1, col1 + i, col2 + j));
            }
        }
        return dp[row][col1][col2] = ans1 + ans;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return func(grid, 0, 0, grid[0].size() - 1);
    }
};