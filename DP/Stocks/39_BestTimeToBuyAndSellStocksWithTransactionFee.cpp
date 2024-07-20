#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int maxProfit(vector<int>& prices,int fee) {
        vector<int> pre(3,0);
        vector<int> curr(3);
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int ans=pre[j];
                if(j){
                    ans = max(prices[i]+pre[!j]-fee,ans);
                }
                else{
                    ans = max(-prices[i]+pre[!j],ans);
                }
                curr[j]=ans;
            }
            pre=curr;
        }
        return curr[0];
    }
};

class Tabulation {
public:
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(3,0));
        for(int i=0;i<3;i++) dp[prices.size()][i]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int ans;
                if(j){
                    ans = max(prices[i]+dp[i+1][!j]-fee,dp[i+1][j]);
                }
                else{
                    ans = max(dp[i+1][j],-prices[i]+dp[i+1][!j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};

class Memoization {
public:
    int fee;
    int func(vector<int>&v, int ind, int bought,vector<vector<int>>&dp){
        if(ind>=v.size()) return 0;
        if(dp[ind][bought]!=-1) return dp[ind][bought];
        int ans;
        if(bought){
            ans = max(v[ind]+func(v,ind+1,!bought,dp)-fee,func(v,ind+1,bought,dp));
        }
        else{
            ans = max(func(v,ind+1,bought,dp),-v[ind]+func(v,ind+1,!bought,dp));
        }
        return dp[ind][bought]=ans;
    }
    int maxProfit(vector<int>& prices, int f) {
        fee=f;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return func(prices,0,0,dp);
    }
};