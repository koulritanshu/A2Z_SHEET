#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501];
    int func(vector<int> &arr, int k, int ind)
    {
        if (ind == arr.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int mx = 0;
        int ans = 0;
        for (int i = ind; i < min((int)arr.size(), ind + k); i++)
        {
            mx = max(mx, arr[i]);
            ans = max(ans, (mx * (i - ind + 1)) + func(arr, k, i + 1));
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        memset(dp, -1, sizeof(dp));
        return func(arr, k, 0);
    }
};
