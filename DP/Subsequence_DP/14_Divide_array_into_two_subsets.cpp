#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(auto &i:nums) s += i;
        vector<bool> prev(s+1,false);
        vector<bool> curr(s+1,false);
        prev[0]=curr[0]=true;
        for(int i=0;i<nums.size();i++){
            curr[nums[i]]=true;
            for(int j=0;j<=s;j++){
                if(!prev[j]) continue;
                if(j==(s-j)) return true;
                curr[j]=true;
                curr[j+nums[i]]=true;
            }
            prev=curr;
        }
        return false;
    }
};

class BottomUp {
    // Tabulation
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i:nums) sum += i;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,0));
        dp[0][0]=true;
        dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            dp[i][nums[i]]=true;
            for(int j=0;j<=sum;j++){
                if(dp[i-1][j]==true){
                    if(j == (sum-j)) return true;
                }
                else continue;
                dp[i][j]=true;
                dp[i][j+nums[i]]=true;
            }
        }
        return false;
    }
};

class TopDown {
    // Memoization
public:
    int sum;
    int dp[201][20001];
    bool func(vector<int>&nums, int ind,int s){
        if(s == (sum - s)) return true;
        if(ind==nums.size()) return false;
        if(dp[ind][s]!=-1) return dp[ind][s];
        return dp[ind][s] = func(nums,ind+1,s)||func(nums,ind+1,s+nums[ind]);
    }
    bool canPartition(vector<int>& nums) {
        sum = 0;
        for(auto &i:nums) sum += i;
        memset(dp,-1,sizeof(dp));
        return func(nums,0,0);
    }
};