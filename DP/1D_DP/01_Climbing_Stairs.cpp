#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int a = 1;
        int b = 1;
        for(int i=2;i<=n;i++){
            int c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};

class Tabulation {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class BottomUp {
public:
    int dp[46];
    int func(int n){
        if(n == 0) return 1;
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = func(n-1) + func(n-2);
        return dp[n] = ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n);
    }   
};