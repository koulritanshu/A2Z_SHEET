#include <bits/stdc++.h>
using namespace std;

class Tabulation {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // problem converted to number of subsets having sum K
        int s = 0;
        for(auto &i:nums){
            s += i;
        }
        if(target>s || target<(-1*s)) return 0;
        int required = (s - target)/2;
        if((s-target)%2) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(required+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
            if(nums[0]<=required) dp[0][nums[0]]=1;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=required;j++){
                int notTake = dp[i-1][j];
	            int take=0;
	            if(nums[i]<=j){
	                take=dp[i-1][j-nums[i]];
	            }
	            dp[i][j] = (notTake+take);
            }
        }
        return dp[nums.size()-1][required];
    }
};

class Memoization {
public:
    int dp[21][2003];
    int func(vector<int>&nums, int ind, int sum, int target){
        if(ind==nums.size()){
            if(sum==target) return 1;
            return 0;
        }
        if(dp[ind][sum+1000]!=-1) return dp[ind][sum+1000];
        int ans = func(nums,ind+1,sum+nums[ind],target);
        ans = ans + func(nums,ind+1,sum-nums[ind],target);
        return dp[ind][sum+1000] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return func(nums,0,0,target);
    }
};