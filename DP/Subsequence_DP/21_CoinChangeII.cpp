#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        vector<int> pre(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
            pre[i]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int ans = pre[j];
                int other = 0;
                if(j>=coins[i])
                other = curr[j-coins[i]];
                curr[j] = ans+other;
            }
            pre=curr;
        }
        int ans = pre[amount];
        return ans;   
    }
};

class Tabulation {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0) return 1;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int ans = dp[i-1][j];
                int other = 0;
                if(j>=coins[i])
                other = dp[i][j-coins[i]];
                dp[i][j] = ans+other;
            }
        }
        int ans = dp[coins.size()-1][amount];
        return ans;   
    }
};

class Memoization {
public:
    int func(vector<int>&coins,int amo,int ind,vector<vector<int>>&dp){
        if(amo==0) return 1;
        if(amo<0||ind<0) return 0;
        if(dp[ind][amo]!=-1) return dp[ind][amo];
        int ans = func(coins,amo,ind-1,dp)+func(coins,amo-coins[ind],ind,dp);
        return dp[ind][amo] = ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return func(coins,amount,coins.size()-1,dp);
    }
};