#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(int ind, vector<int> &nums, int curr)
    {
        if (ind == nums.size())
            return 0;
        int sum = 0;
        sum = sum + func(ind + 1, nums, curr);
        int x = curr ^ nums[ind];
        sum = sum + x + func(ind + 1, nums, x);
        return sum;
    }
    int subsetXORSum(vector<int> &nums)
    {
        return func(0, nums, 0);
    }
};