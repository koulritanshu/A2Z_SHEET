#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s = (s + nums[i]) % k;
            if (s == 0 && i > 0)
                return true;
            if (mp.find(s) != mp.end())
            {
                int ind = mp[s];
                int diff = i - ind;
                if (diff > 1)
                    return true;
            }
            else
                mp[s] = i;
        }
        return false;
    }
};