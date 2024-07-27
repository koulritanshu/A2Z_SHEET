#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int numberOfConsecutiveOnes(int n)
    {
        int dp[n + 1];
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 3;
        int prev = 1;
        int prev2 = 2;
        // (3 -> 1) , (4 -> 2) , (5 -> 3), (6 -> 5)
        for (int i = 4; i <= n; i++)
        {
            int multi = ((dp[i - 1] % MOD) * (2 % MOD)) % MOD;
            multi = ((multi % MOD) + (prev2 % MOD)) % MOD;
            int temp = prev2;
            prev2 = (prev + prev2) % MOD;
            prev = temp;
            dp[i] = multi;
        }
        return dp[n];
    }
};