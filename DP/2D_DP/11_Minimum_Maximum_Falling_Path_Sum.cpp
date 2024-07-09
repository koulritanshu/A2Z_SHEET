#include <bits/stdc++.h>
using namespace std;

class SpaceOptimizaion {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1) return matrix[0][0];
        vector<int> dp(matrix.size(),0);
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            dp[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            int pre = dp[0];
            for(int j=0;j<n;j++){
                int mini = dp[j];
                if(j==0){
                    mini = min(mini,dp[j+1]);
                }
                else if(j==n-1){
                    mini = min(mini,pre);
                }
                else{
                    mini = min(mini,min(dp[j+1],pre));
                }
                pre = dp[j];
                dp[j] = matrix[i][j] + mini;
                if(i==n-1){
                    ans = min(ans,dp[j]);
                }
            }
        }
        return ans;
    }
};

class BottomUp {
    // Tabulation
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),0));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini;
                if(j==0){
                    mini = min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1){
                    mini = min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    mini = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]);
                }
                dp[i][j] = matrix[i][j] + mini;
            }
        }
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }   
        return ans;
    }
};

class TopDown {
    // Memoization
public:
    int func(int i, int j, int n, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(j>= n || j<0) return 10000;
        if(dp[i][j]!=-100000) return dp[i][j];
        int ans = matrix[i][j];
        ans += min(func(i+1,j-1,n,matrix,dp),min(func(i+1,j,n,matrix,dp),func(i+1,j+1,n,matrix,dp)));
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix.size()+1,-100000));
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ans = min(ans,func(0,i,matrix.size(),matrix,dp));
        }
        return ans;
    }
};