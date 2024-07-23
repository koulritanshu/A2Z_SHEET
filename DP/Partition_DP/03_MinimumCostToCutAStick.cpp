#include <bits/stdc++.h>
using namespace std;

class Tabulation {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));
        for(int i=cuts.size()-2;i>=1;i--){
            for(int j=i;j<=cuts.size()-2;j++){
                int steps = 1e9;
                for(int k=i;k<=j;k++){
                    int curr = dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1];
                    steps = min(steps,curr);
                }
                dp[i][j] = steps;
            }
        }
        return dp[1][cuts.size()-2];
    }
};

class Memoization {
public:
    int dp[105][105];
    int func(int i, int j, vector<int>&v){
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int steps = 1e9;
        for(int k=i;k<=j;k++){
            int curr = func(i,k-1,v) + func(k+1,j,v) + v[j+1]-v[i-1];
            steps = min(steps,curr);
        }
        return dp[i][j] = steps;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return func(1,cuts.size()-2,cuts);
    }
};