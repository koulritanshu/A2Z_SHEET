#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void func(vector<vector<int>> &ans, int ind, vector<int> &curr, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        func(ans, ind + 1, curr, nums);
        curr.push_back(nums[ind]);
        func(ans, ind + 1, curr, nums);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        func(ans, 0, v, nums);
        return ans;
    }
};