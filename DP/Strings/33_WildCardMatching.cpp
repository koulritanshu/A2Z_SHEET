#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
public:
    bool isMatch(string s, string p) {
        vector<bool> pre(p.size()+1,false);
        vector<bool> curr(p.size()+1,false);
        pre[0]=true;
        for(int i=1;i<=p.size();i++){
            if(p[i-1]=='*') pre[i] = true;
            else break;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j] = pre[j-1];
                else if(p[j-1]=='*') curr[j] = pre[j-1] || pre[j] || curr[j-1];
                else curr[j] = false;
            }
            pre=curr;
        }
        return pre[p.size()];
    }
};


class Tabulation {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        for(int i=1;i<=p.size();i++){
            if(p[i-1]=='*') dp[0][i] = true;
            else break;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[s.size()][p.size()];
    }
};

class Memoization {
public:
    bool func(string &s, string &p, int i, int j,vector<vector<int>>&dp){
        if(i==-1){
            if(j==-1) return true;
            while(j>=0) {if(p[j]!='*') return false;j--;}
            return true;
        }
        if(j==-1) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(s[i]==p[j] || p[j]=='?') ans = func(s,p,i-1,j-1,dp);
        else if(p[j]=='*') ans = func(s,p,i-1,j-1,dp) || func(s,p,i-1,j,dp) || func(s,p,i,j-1,dp);
        else return false;
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return func(s,p,s.size()-1,p.size()-1,dp);
    }
};