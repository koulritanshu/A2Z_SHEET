#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int i = 0, j = 0, ans = INT_MIN, currCost = 0;
        while (j < s.size())
        {
            currCost += abs(s[j] - t[j]);
            while (currCost > maxCost)
            {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};