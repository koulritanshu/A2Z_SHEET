#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        if(obs[0][0]==1||obs[obs.size()-1][obs[0].size()-1]==1) return 0;
        vector<int> dp(obs[0].size(),0);
        dp[0]=1;
        for(int i=1;i<obs[0].size();i++){
            if(obs[0][i]==1) dp[i]=0;
            else dp[i]=dp[i-1];
        }
        for(int i=1;i<obs.size();i++){
            int pre = dp[0];
            if(obs[i][0]==1){
                dp[0]=0;
                pre=0;
            }
            for(int j=1;j<obs[0].size();j++){
                if(obs[i][j]==1){
                    pre = 0;
                    dp[j] = 0;
                }
                else{
                    int curr = pre + dp[j];
                    pre = curr;
                    dp[j] = curr;
                }
            }
        }
        return dp[obs[0].size()-1];
    }
};

class BottomUp {
    // Tabulation
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        if(obs[0][0]==1||obs[obs.size()-1][obs[0].size()-1]==1) return 0;
        vector<vector<int>> dp(obs.size(),vector<int>(obs[0].size(),0));
        dp[0][0] = 1;
        for(int i=0;i<obs.size();i++){
            for(int j=0;j<obs[i].size();j++){
                if(i==0&&j==0) continue;
                if(obs[i][j]==1){
                    dp[i][j]=0;
                }              
                else{
                    if(i-1>=0) dp[i][j]+=dp[i-1][j];
                    if(j-1>=0) dp[i][j]+=dp[i][j-1];
                }  
            }
        }    
        return dp[obs.size()-1][obs[0].size()-1];
    }
};

class TopDown {
    // Memoization
public:
    int dp[101][101];
    int func(vector<vector<int>>&obs,int i, int j){
        if(i==obs.size()||j==obs[0].size()) return 0;
        if(obs[i][j]==1)return 0;
        if(i==obs.size()-1&&j==obs[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = func(obs,i+1,j)+func(obs,i,j+1);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        memset(dp,-1,sizeof(dp));
        return func(obs,0,0);
    }
};