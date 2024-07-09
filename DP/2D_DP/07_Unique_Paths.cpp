#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int uniquePaths(int m, int n) {
        vector<int> previous(n,1);
        for(int i=1;i<m;i++){
            int pre = 1;
            previous[0] = 1;
            for(int j=1;j<n;j++){
                int curr = pre + previous[j];
                previous[j] = curr;
                pre = curr;
            }
        } 
        return previous[n-1];
    }
};

class BottomUp {
    // Tabulation
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        } 
        return dp[m-1][n-1];
    }
};

class TopDown {
    // Memoization
public:
    int dp[101][101];
    int func(int m, int n, int i, int j){
        if(i==m||j==n) return 0;
        if(i==(m-1)&&j==(n-1)) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=func(m,n,i+1,j)+func(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return func(m,n,0,0);
    }
};