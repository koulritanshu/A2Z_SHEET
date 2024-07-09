#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        int a = points[0][0];
        int b = points[0][1];
        int c = points[0][2];
        for(int i=1;i<n;i++){
            int d = points[i][0] + max(b,c);
            int e = points[i][1] + max(a,c);
            int f = points[i][2] + max(a,b);
            a = d;
            b = e;
            c = f;
        }
        return max(a,max(b,c));
    }
};

class BottomUp {
    // Tabulation
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];
        for(int i=1;i<n;i++){
            dp[i][0] = points[i][0] + max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = points[i][1] + max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = points[i][2] + max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }
};

class TopDown {
    // Memoization
  public:
    int func(vector<vector<int>>&v, int ind,int col,vector<vector<int>>&dp){
        if(ind==v.size()-1) return v[ind][col];
        if(dp[ind][col]!=-1) return dp[ind][col];
        int ans = v[ind][col];
        if(col==0){
            ans += max(func(v,ind+1,2,dp),func(v,ind+1,1,dp));
        }
        else if(col==1){
            ans += max(func(v,ind+1,0,dp),func(v,ind+1,2,dp));
        }
        else{
            ans += max(func(v,ind+1,0,dp),func(v,ind+1,1,dp));
        }
        return dp[ind][col] = ans;
    }
    int maximumPoints(vector<vector<int>>& v, int n) {
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return (max(func(v,0,0,dp),max(func(v,0,1,dp),func(v,0,2,dp))));
    }
};