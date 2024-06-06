#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

class Solution
{
public:
    int MOD = 1e9 + 7;
    int dp[501][501];
    int func(string &s1, string &s2, int ind1, int ind2)
    {
        if (ind2 == s2.size())
            return 1;
        if (ind1 == s1.size())
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2] % MOD;
        int ans = 0;
        ans = ((ans % MOD) + (func(s1, s2, ind1 + 1, ind2) % MOD)) % MOD;
        if (s1[ind1] == s2[ind2])
        {
            ans = ((ans % MOD) + (func(s1, s2, ind1 + 1, ind2 + 1) % MOD)) % MOD;
        }
        return dp[ind1][ind2] = ans % MOD;
    }
    int countWays(string s1, string s2)
    {
        if (s2.size() > s1.size())
            return 0;
        if (s1.size() == s2.size())
        {
            if (s1 == s2)
                return 1;
            else
                return 0;
        }
        memset(dp, -1, sizeof(dp));
        return func(s1, s2, 0, 0) % MOD;
    }
};