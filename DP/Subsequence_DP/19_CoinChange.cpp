#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        vector<int> dp2(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[i] = i / coins[0];
            }
            else{
                dp[i] = 1e9;
            }
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int amo=0;amo<=amount;amo++){
                int ans = dp[amo];
                int other = 1e9;
                if(coins[ind]<=amo)
                other = 1 + dp2[amo-coins[ind]];
                dp2[amo] = min(ans,other);
            }
            dp=dp2;
        }
        int ans = dp[amount];
        if(ans==1e9) return -1;
        return ans; 
    }
};

class Tabulation {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int amo=0;amo<=amount;amo++){
                int ans = dp[ind-1][amo];
                int other = 1e9;
                if(coins[ind]<=amo)
                other = 1 + dp[ind][amo-coins[ind]];
                dp[ind][amo] = min(ans,other);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans==1e9) return -1;
        return ans; 
    }
};

class Memoization {
public:
    int dp[10001][14];
    int func(vector<int>&coins,int amo,int ind){
        if(amo==0) return 0;
        if(amo<0||ind<0) return INT_MAX-100;
        if(dp[amo][ind]!=-1) return dp[amo][ind];
        int ans = func(coins,amo,ind-1);
        ans = min(ans,1+func(coins,amo-coins[ind],ind));
        return dp[amo][ind] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = func(coins,amount,coins.size()-1);
        if(ans>=(INT_MAX-100000)) return -1;
        return ans;
    }
};