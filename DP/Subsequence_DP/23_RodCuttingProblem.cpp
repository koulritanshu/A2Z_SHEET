#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int cutRod(int price[], int n) {
        vector<int> pre(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=0;i<=n;i++){
            pre[i] = price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int ans = pre[j];
                int other = 0;
                if(j>=(i+1))
                other = price[i] + curr[j-i-1];
                curr[j] = max(ans,other);
            }
            pre = curr;
        }
        return pre[n];
    }
};

class Tabulation{
public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int ans = dp[i-1][j];
                int other = 0;
                if(j>=(i+1))
                other = price[i] + dp[i][j-i-1];
                dp[i][j] = max(ans,other);
            }
        }
        return dp[n-1][n];
    }
};

class Memoization{
public:
    int dp[1001][1001];
    int func(int price[], int n, int ind){
        if(ind<0||n==0) return 0;
        if(dp[ind][n]!=-1) return dp[ind][n];
        int ans = func(price,n,ind-1);
        int other = 0;
        if(n>=(ind+1))
        other = price[ind] + func(price,n-ind-1,ind);
        return dp[ind][n] = max(ans,other);
    }
};

