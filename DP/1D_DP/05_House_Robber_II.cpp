#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int rob2(vector<int>& nums,int ind) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int a = nums[0+ind]; // dp[0] 
        int b = nums[1+ind];  // dp[1]
        int pre = nums[2+ind]+a; // dp[2]
        for(int i=3+ind;i<nums.size();i++){
            int c = nums[i] + max(a,b);// dp[3] requires dp[1] and dp[0]
            a = b; // a = dp[1]
            b = pre; // b = dp[2]
            pre = c; // pre = dp[3]
        }
        return max(b,pre);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int x = nums[nums.size()-1];
        nums.pop_back();
        int one = rob2(nums,0);
        nums.push_back(x);
        one = max(one,rob2(nums,1));
        return one;
    }
};

class BottomUp {
public:
    int rob2(vector<int>& nums,int ind) {
        vector<int> dp(nums.size(),0);
        dp[0+ind] = nums[0+ind];
        dp[1+ind] = nums[1+ind];
        for(int i=2+ind;i<nums.size();i++){
            if(i==2)
            dp[i] = nums[i] + dp[i-2];
            else
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int x = nums[nums.size()-1];
        nums.pop_back();
        int one = rob2(nums,0);
        nums.push_back(x);
        one = max(one,rob2(nums,1));
        return one;
    }
};

class TopDown {
    // Memoization
public:
    int dp[101];
    int func(vector<int>&nums, int ind){
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int sum = nums[ind]+func(nums,ind+2);
        sum = max(sum,func(nums,ind+1));
        return dp[ind] = sum;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int x = nums[nums.size()-1];
        nums.pop_back();
        int one = func(nums,0);
        nums.push_back(x);
        memset(dp,-1,sizeof(dp));
        one = max(one,func(nums,1));
        return one;
    }
};