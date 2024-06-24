#include <bits/stdc++.h>
using namespace std;

// You are given an integer array nums with length n.

// The cost of a 
// subarray
//  nums[l..r], where 0 <= l <= r < n, is defined as:

// cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

// Your task is to split nums into subarrays such that the total cost of the subarrays is maximized, ensuring each element belongs to exactly one subarray.

// Formally, if nums is split into k subarrays, where k > 1, at indices i1, i2, ..., ik − 1, where 0 <= i1 < i2 < ... < ik - 1 < n - 1, then the total cost will be:

// cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)

// Return an integer denoting the maximum total cost of the subarrays after splitting the array optimally.

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    long long dp[100001];
    long long func(vector<int>&nums, int ind){
        if(ind==nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long one = nums[ind] + func(nums,ind+1);
        long long other = nums[ind];
        if(ind+1<nums.size()) other = other - nums[ind+1] + func(nums,ind+2);
        return dp[ind] = max(one,other);
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return func(nums,0);
    }
};
 