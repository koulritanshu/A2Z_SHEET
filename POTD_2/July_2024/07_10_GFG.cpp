#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    dp[i+1][j+1] = 1+min(dp[i][j+1],min(dp[i][j],dp[i+1][j]));
                    ans = max(ans,dp[i+1][j+1]);
                }
            }
        }
        return ans;
    }
};