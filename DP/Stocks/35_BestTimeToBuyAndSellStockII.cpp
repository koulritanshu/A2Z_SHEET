#include <bits/stdc++.h>
using namespace std;

class Greedy {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans += max(0,prices[i]-prices[i-1]);
        } 
        return ans;
    }
};

class Memoization {
public:
    int func(vector<int>&v, int ind, int bought,vector<vector<int>>&dp){
        if(ind==v.size()) return 0;
        if(dp[ind][bought]!=-1) return dp[ind][bought];
        if(bought){
            int sell = v[ind] + func(v,ind+1,!bought,dp);
            int not_sell = func(v,ind+1,bought,dp);
            return dp[ind][bought] = max(sell,not_sell);    
        }
        else{
            int buy = -v[ind] + func(v,ind+1,!bought,dp);
            int ignore = func(v,ind+1,bought,dp);
            return dp[ind][bought] = max(buy,ignore);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return func(prices,0,0,dp);
    }
};

class Tabulation {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+4,vector<int>(4,0));
        dp[prices.size()][0]=dp[prices.size()][1]=0;    
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==1){
                    int sell = prices[i] + dp[i+1][0];
                    int not_sell = dp[i+1][1];
                    dp[i][j] = max(sell,not_sell);
                }
                else{
                    int buy = -prices[i] + dp[i+1][1];
                    int ignore = dp[i+1][0];
                    dp[i][j] = max(buy,ignore);
                }
            }
        }
        return dp[0][0];
    }
};