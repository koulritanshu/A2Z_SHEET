#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        // required to print the LIS
        vector<int> dp(n+1,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};

class Dp {
public:
    int dp[2501][2501];
    int memoization(vector<int>&nums, int ind, int pre){
        if(ind==nums.size()) return 0;
        if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];
        int ans = memoization(nums,ind+1,pre);
        if(pre==-1 || nums[ind]>nums[pre]){
            ans = max(ans,1+memoization(nums,ind+1,ind));
        }
        return dp[ind][pre+1]=ans;
    }
    int tabulation(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,0));
        for(int i=0;i<=nums.size();i++){
            dp[nums.size()][i] = 1;
        }
        int anss = 1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>=0;j--){
                int ans = dp[i+1][j];
                if(i>j && nums[i]>nums[j]){
                    ans = max(ans,1+dp[i+1][i]);
                }
                dp[i][j] = ans;
                anss = max(anss,ans);
            }
        }
        return anss;
    }
    int spaceOptimization(vector<int>& nums) {
        vector<int> pre(nums.size()+1,0);
        for(int i=0;i<=nums.size();i++){
            pre[i] = 1;
        }
        int anss = 1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>=0;j--){
                int ans = pre[j];
                if(i>j && nums[i]>nums[j]){
                    ans = max(ans,1+pre[i]);
                }
                pre[j] = ans;
                anss = max(anss,ans);
            }
        }
        return anss;
    }
};