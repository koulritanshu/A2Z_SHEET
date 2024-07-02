#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int a = nums[0]; // dp[0] 
        int b = nums[1];  // dp[1]
        int pre = nums[2]+a; // dp[2]
        for(int i=3;i<nums.size();i++){
            int c = nums[i] + max(a,b);// dp[3] requires dp[1] and dp[0]
            a = b; // a = dp[1]
            b = pre; // b = dp[2]
            pre = c; // pre = dp[3]
        }
        return max(b,pre);
    }
};


class BottomUp {
    // Tabulation
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i=2;i<nums.size();i++){
            if(i==2)
            dp[i] = nums[i] + dp[i-2];
            else
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};

class TopDown {
    // Memoization
public:
    int dp[101];
    int func(vector<int>&nums,int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans = func(nums,ind+1);
        ans = max(ans,func(nums,ind+2)+nums[ind]);
        return dp[ind] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return func(nums,0);
    }
};