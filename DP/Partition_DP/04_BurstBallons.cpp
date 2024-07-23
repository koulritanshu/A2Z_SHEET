#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[303][303];
    int func(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int steps = 0;
        for(int k=i;k<=j;k++){
            int curr = func(i,k-1,nums)+func(k+1,j,nums) + nums[i-1]*nums[k]*nums[j+1];
            steps = max(steps,curr);
        }
        return dp[i][j]=steps;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-2;i>=1;i--){
            for(int j=i;j<=nums.size()-2;j++){
                int steps = 0;
                for(int k=i;k<=j;k++){
                    int curr = dp[i][k-1] + dp[k+1][j] + (nums[i-1]*nums[k]*nums[j+1]);
                    steps = max(steps,curr);
                }
                dp[i][j] = steps;
            }
        }
        return dp[1][nums.size()-2];
    }
};