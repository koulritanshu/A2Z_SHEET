#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LCSof3(string a, string b, string c, int n1, int n2, int n3)
    {
        int dp[n1 + 1][n2 + 2][n3 + 3];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                for (int k = 1; k <= n3; k++)
                {
                    if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                    {
                        int a = dp[i - 1][j][k];
                        a = max(a, dp[i][j - 1][k]);
                        a = max(a, dp[i][j][k - 1]);
                        dp[i][j][k] = a;
                    }
                }
            }
        }
        return dp[a.size()][b.size()][c.size()];
    }
};