#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int maxi = 0;
        for (auto &i : nums)
        {
            maxi = max(maxi, i);
        }
        vector<int> v(nums.size() + maxi + 1, 0);
        for (auto &i : nums)
        {
            v[i]++;
        }
        int ans = 0;
        for (int i = 0; i < nums.size() + maxi; i++)
        {
            int curr = v[i];
            if (!curr)
                continue;
            int duplicates = curr - 1;
            curr = 1;
            ans += duplicates;
            v[i + 1] += duplicates;
        }
        return ans;
    }
};