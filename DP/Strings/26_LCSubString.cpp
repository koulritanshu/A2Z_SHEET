#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans = 0;
        vector<int> dp1(S2.size()+1,0);
        vector<int> dp2(S2.size()+1,0);
        for(int i=1;i<=S1.size();i++){
            for(int j=1;j<=S2.size();j++){
                if(S1[i-1]==S2[j-1]){
                    dp2[j] = 1+dp1[j-1];
                    ans=max(ans,dp2[j]);
                }
                else{
                    dp2[j]=0;
                }
            }
            dp1=dp2;
        }   
        return ans;
    }
};

class Tabulation{
public:    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans = 0;
        vector<vector<int>> dp(S1.size()+1,vector<int>(S2.size()+1,0));
        for(int i=1;i<=S1.size();i++){
            for(int j=1;j<=S2.size();j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }   
        return ans;
    }
};