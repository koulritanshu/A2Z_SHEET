#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoization(vector<int>&arr, int ind, int sign,vector<vector<int>>&dp){
        if(ind==arr.size()) return 0;
        if(dp[ind][sign]!=-1) return dp[ind][sign];
        int ans = memoization(arr,ind+1,sign,dp);
        if(sign){
            if(ind==0 || arr[ind]>arr[ind-1]){
                ans = max(ans,1+memoization(arr,ind+1,!sign,dp));
            }
        }
        else{
            if(ind==0 || arr[ind]<arr[ind-1]){
                ans = max(ans,1+memoization(arr,ind+1,!sign,dp));
            }
        }
        return dp[ind][sign] = ans;
    }  
    int tabulation(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
        dp[0][0] = 1;
        dp[0][1] = 1;
        // for greater than use 1
        // for lesser than use 0
        
        // 7 2 10 9 9 6 7 
        // 
        int ans = 1;
        for(int i=1;i<arr.size();i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            if(arr[i]>arr[i-1]){
                dp[i][0] = dp[i-1][1]+1;
                ans = max(ans,dp[i][0]);
            }
            else if(arr[i]<arr[i-1]){
                dp[i][1] = dp[i-1][0]+1;
                ans = max(ans,dp[i][1]);
            }
        }
        // for(int i=0;i<arr.size();i++){
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
        return ans;
    }
    int alternatingMaxLength(vector<int>& arr) {
        // vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
        // dp[0][0] = 1;
        // dp[0][1] = 1;
        // for greater than use 1
        // for lesser than use 0
        
        // 7 2 10 9 9 6 7 
        // 
        int gre=1;
        int sma=1;
        int ans = 1;
        for(int i=1;i<arr.size();i++){
            int curr_gre = gre;
            int curr_sma = sma;
            if(arr[i]>arr[i-1]){
                // dp[i][0] = dp[i-1][1]+1;
                curr_sma = gre+1;
                ans = max(ans,curr_sma);
            }
            else if(arr[i]<arr[i-1]){
                // dp[i][1] = dp[i-1][0]+1;
                curr_gre = sma+1;
                ans = max(ans,curr_gre);
            }
            gre=curr_gre;
            sma=curr_sma;
        }
        // for(int i=0;i<arr.size();i++){
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
        return ans;
    }
};