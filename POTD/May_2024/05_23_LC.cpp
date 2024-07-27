// https://leetcode.com/problems/the-number-of-beautiful-subsets/?envType=daily-question&envId=2024-05-23

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(vector<int> &nums, int k, int ind, unordered_map<int, int> &mp)
    {
        if (ind == nums.size())
            return 1;
        int ans = func(nums, k, ind + 1, mp);
        if (mp[nums[ind] - k] == 0 && mp[nums[ind] + k] == 0)
        {
            mp[nums[ind]]++;
            ans += func(nums, k, ind + 1, mp);
            mp[nums[ind]]--;
        }
        return ans;
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        return func(nums, k, 0, mp) - 1;
    }
};