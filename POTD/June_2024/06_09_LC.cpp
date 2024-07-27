#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s = (s + nums[i] % k + k) % k;
            mp[s]++;
        }
        mp[0]++;
        int ans = 0;
        for (auto i : mp)
        {
            int freq = i.second;
            ans += (freq * (freq - 1)) / 2;
        }
        return ans;
    }
};