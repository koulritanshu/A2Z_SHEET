#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> pre(W+1,0);
        vector<int> curr(W+1,0);
        for(int i=0;i<=W;i++){
            pre[i] = (i/wt[0]) * val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notPick = pre[j];
                int pick = 0;
                if(wt[i]<=j)
                pick = val[i]+curr[j-wt[i]];
                curr[j] = max(notPick,pick);
            }
            pre=curr;
        }
        return pre[W];
    }
};

class Tabulation{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        for(int i=0;i<=W;i++){
            dp[0][i] = (i/wt[0]) * val[0];
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notPick = dp[i-1][j];
                int pick = 0;
                if(wt[i]<=j)
                pick = val[i]+dp[i][j-wt[i]];
                dp[i][j] = max(notPick,pick);
            }
        }
        return dp[N-1][W];
    }
};

class Memoization{
public:
    int dp[1001][1001];
    int func(int val[], int wt[], int ind,int W){
        if(W==0||ind<0) return 0;
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notPick = func(val,wt,ind-1,W);
        int pick = 0;
        if(wt[ind]<=W)
        pick = val[ind]+func(val,wt,ind,W-wt[ind]);
        return dp[ind][W] = max(notPick,pick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return func(val,wt,N-1,W);
    }
};