#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> pre(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                pre[j][k]=0;
            }
        }
        pre[0][2]=pre[1][2]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=1;k++){
                    int ans;
                    if(j==1){
                        ans = max(prices[i]+pre[0][k+1],pre[j][k]);
                    }
                    else{
                        ans = max(-prices[i]+pre[1][k],pre[j][k]);
                    }
                    curr[j][k] = ans;
                }
            }
            pre=curr;
        }
        return pre[0][0];
    }
};

class Tabulation {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(4,vector<int>(4,0)));
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                dp[prices.size()][j][k]=0;
            }
        }
        for(int i=0;i<=prices.size();i++){
            for(int j=0;j<=1;j++){
                dp[i][j][2]=0;
            }
        }
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=1;k++){
                    int ans;
                    if(j==1){
                        ans = max(prices[i]+dp[i+1][0][k+1],dp[i+1][j][k]);
                    }
                    else{
                        ans = max(-prices[i]+dp[i+1][1][k],dp[i+1][j][k]);
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
};

class Memoization {
public:
    int func(vector<int>&v, int ind,int bought, int cnt,vector<vector<vector<int>>>&dp){
        if(ind==v.size()) return 0;
        if(cnt==2) return 0;
        if(dp[ind][bought][cnt]!=-1) return dp[ind][bought][cnt];
        int ans;
        if(bought){
            ans = max(v[ind]+func(v,ind+1,!bought,cnt+1,dp),func(v,ind+1,bought,cnt,dp));
        }
        else{
            ans = max(-v[ind]+func(v,ind+1,!bought,cnt,dp),func(v,ind+1,bought,cnt,dp));
        }
        return dp[ind][bought][cnt]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return func(prices,0,0,0,dp);
    }
};