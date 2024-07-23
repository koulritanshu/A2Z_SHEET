#include <bits/stdc++.h>
using namespace std;

class Ncube {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int dp[2003];
    // int func(string &s, int i){
    //     if(i>=s.size()-1) return 0;
    //     if(check(s,i,s.size()-1)) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans = INT_MAX;
    //     for(int j=i;j<s.size();j++){
    //         if(check(s,i,j)){
    //             ans = min(ans,func(s,j+1)+1);
    //         }
    //     }
    //     return dp[i] = ans;
    // }
    int minCut(string &s) {
        // memset(dp,-1,sizeof(dp));
        // return func(s,0);
        vector<int> dp(s.size()+1,0);
        if(check(s,0,s.size()-1)) return 0;
        for(int i=s.size()-1;i>=0;i--){
            if(check(s,i,s.size()-1)){
                dp[i] = 0;
                continue;
            }
            int steps = 1e9;
            for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    steps = min(steps,dp[j+1]+1);
                }
            }
            dp[i] = steps;
        }
        return dp[0];
    }   
};

class Npower4 {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // int dp[2003][2003];
    // int func(string &s, int i, int j){
    //     if(i>=j) return 0;
    //     if(check(s,i,j)) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int steps = 1e9;
    //     for(int k=i;k<j;k++){
    //         int curr = func(s,i,k) + func(s,k+1,j) + 1;
    //         steps = min(steps,curr);
    //     }
    //     return dp[i][j] = steps;
    // }
    int minCut(string &s) {
        // memset(dp,-1,sizeof(dp));
        // return func(s,0,s.size()-1);
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,0));
        if(check(s,0,s.size()-1)) return 0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                int steps = 1e9;
                for(int k=i;k<j;k++){
                    steps=min(steps,dp[i][k]+dp[k+1][j]+1);
                }
                dp[i][j] = steps;
            }
        }
        return dp[0][s.size()-1];
    }
};