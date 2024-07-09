#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(),0);
        dp[0] = grid[0][0];
        for(int i=1;i<grid[0].size();i++){
            dp[i] = grid[0][i]+dp[i-1];
        }
        for(int i=1;i<grid.size();i++){
            dp[0] += grid[i][0];
            for(int j=1;j<grid[0].size();j++){
                int c = grid[i][j] + min(dp[j],dp[j-1]);
                dp[j] = c;
            }
        }
        return dp[grid[0].size()-1];
    }
};

class BottomUp {
    // Tabulation
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                dp[i][j] = grid[i][j];
                int addi = INT_MAX;
                if(i-1>=0) addi=min(addi,dp[i-1][j]);
                if(j-1>=0) addi=min(addi,dp[i][j-1]);
                if(addi==INT_MAX) addi=0;
                dp[i][j] += addi;
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

class TopDown {
    // Memoization
public:
    int dp[201][201];
    int func(vector<vector<int>>&grid,int i, int j){
        if(i==grid.size()-1&&j==grid[0].size()-1) return grid[i][j];
        if(i==grid.size()||j==grid[0].size()) return INT_MAX-10000;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = grid[i][j] + min(func(grid,i+1,j),func(grid,i,j+1));
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return func(grid,0,0);
    }
};