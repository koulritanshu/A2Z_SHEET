#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        // 0 3 6 7 7
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] == 0)
            return -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int freq = nums.size() - i;
            // cout << freq << " " << nums[i] << endl;
            if (freq <= nums[i] && (i == 0 || freq > nums[i - 1]))
                return freq;
        }
        return -1;
    }
};