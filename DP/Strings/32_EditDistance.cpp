#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int minDistance(string text1, string text2) {
        // vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        vector<int> pre(text2.size()+1,0);
        vector<int> curr(text2.size()+1,0);
        // for(int i=0;i<=text1.size();i++){
        //     dp[i][0] = i;
        // }
        for(int j=0;j<=text2.size();j++){
            pre[j] = curr[j] = j;
        }
        for(int i=1;i<=text1.size();i++){
            curr[0]=i;
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = pre[j-1];
                }
                else{
                    curr[j] = min(1+curr[j-1],min(1+pre[j-1],1+pre[j]));
                }
            }
            pre=curr;
        }
        return curr[text2.size()];
    }
};

class Tabulation {
public:
    int minDistance(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<=text1.size();i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=text2.size();j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(1+dp[i][j-1],min(1+dp[i-1][j-1],1+dp[i-1][j]));
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

class Memoization {
public:
    int func(string &text1, string &text2,int i, int j,vector<vector<int>>&dp){
        if(j==text2.size()) return (text1.size()-i);
        if(i==text1.size()) return (text2.size()-j);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        if(text1[i]!=text2[j]) 
        ans = min(1+func(text1,text2,i,j+1,dp),min(1+func(text1,text2,i+1,j+1,dp),1+func(text1,text2,i+1,j,dp)));
        else
        ans = func(text1,text2,i+1,j+1,dp);
        return dp[i][j] = ans;
    }
    int minDistance(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return func(text1,text2,0,0,dp);
    }
};