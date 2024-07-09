#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(),INT_MAX);
        dp[0] = triangle[0][0];
        int ans = INT_MAX;
        for(int i=1;i<triangle.size();i++){
            int pre=dp[0];
            dp[0] += triangle[i][0];
            for(int j=1;j<=i;j++){
                int curr = triangle[i][j]+min(dp[j],pre);
                pre=dp[j];
                dp[j]=curr;
            }
        }
        for(int i=0;i<triangle.size();i++){
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};

class BottomUp {
    // Tabulation
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),1e7));
        dp[0][0] = triangle[0][0];
        int ans = INT_MAX;
        for(int i=1;i<triangle.size();i++){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for(int j=1;j<=i;j++){
                dp[i][j] = triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        for(int i=0;i<triangle.size();i++){
            ans = min(ans,dp[triangle.size()-1][i]);
        }
        return ans;
    }
};

class TopDown {
    // Memoization
public:
    int dp[201][201];
    int func(vector<vector<int>>&triangle,int row, int col){
        if(row==triangle.size()-1&&col<triangle[row].size()) return triangle[row][col];
        if(col==triangle[row].size()) return INT_MAX-100000;
        if(dp[row][col]!=-1) return dp[row][col];
        int ans = triangle[row][col]+min(func(triangle,row+1,col),func(triangle,row+1,col+1));
        return dp[row][col] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return func(triangle,0,0);
    }
};