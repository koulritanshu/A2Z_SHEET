#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        // for(int i=0;i<=s.size();i++) dp[i][0]=1; 
        // for(int i=1;i<=s.size();i++){
        //     for(int j=1;j<=t.size();j++){
        //         long long int ans = dp[i-1][j];
        //         if(s[i-1]==t[j-1])
        //         ans = ans + dp[i-1][j-1];
        //         dp[i][j]=ans;
        //     }
        // }
        // return dp[s.size()][t.size()];
        vector<int> pre(t.size()+1,0);
        vector<int> curr(t.size()+1,0);
        pre[0]=1;
        curr[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                long long ans = pre[j];
                if(s[i-1]==t[j-1]) ans = ans + pre[j-1];
                curr[j] = ans;
            }
            pre=curr;
        }
        return pre[t.size()];
    }
};

class Memoization {
public:
    int func(string &s, string &t,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind2==t.size()) return 1;
        if(ind1==s.size()) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int ans = func(s,t,ind1+1,ind2,dp);
        if(s[ind1]==t[ind2])
        ans = ans + func(s,t,ind1+1,ind2+1,dp);
        return dp[ind1][ind2] = ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return func(s,t,0,0,dp);
    }
};

class Tabulation {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++) dp[i][0]=1; 
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                long long int ans = dp[i-1][j];
                if(s[i-1]==t[j-1])
                ans = ans + dp[i-1][j-1];
                dp[i][j]=ans;
            }
        }
        return dp[s.size()][t.size()];
    }
};