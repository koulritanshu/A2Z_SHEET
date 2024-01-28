#include <bits/stdc++.h>
using namespace std;

// Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings. For example, "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.

// A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than the sum of the digits of the sub-group immediately right to it. Your task is to determine the total number of valid groupings that could be done for a given string.

// Input:
// str = "1119"
// Output:
// 7
// Explanation:
// One valid grouping is {"1", "11", "9"}.
// Sum of digits of first sub-group ("1") is 1,
// for the second sub-group ("11"), it is 2,
// and for the third one ("9"), it is 9.
// As the sum of digits of the sub-groups is
// in increasing order, it forms a valid grouping.
// Other valid grouping are {"1", "119"}, {"1","1","19"},
// {"1","1","1","9"}, {"11","19"}, {"111","9"} and {"1119"}
// are six other valid groupings.

class Solution
{
public:
    int dp[101][911];
    int func(string &str, int ind, int sum)
    {
        if (ind == str.size())
            return 1;
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        int x = 0;
        int ans = 0;
        for (int i = ind; i < str.size(); i++)
        {
            x += (str[i] - '0');
            if (x >= sum)
            {
                ans += func(str, i + 1, x);
            }
        }
        return dp[ind][sum] = ans;
    }
    int TotalCount(string str)
    {
        memset(dp, -1, sizeof(dp));
        return func(str, 0, 0);
    }
};