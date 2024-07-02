#include <bits/stdc++.h>
using namespace std;

class BottomUp {
    // Tabulation
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        if(n==1) return 0;
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int ans = INT_MAX;
            for(int j=max(i-k,0);j<i;j++){
                ans = min(ans,abs(height[i]-height[j])+dp[j]);
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }
};

class TopDown {
    // Memoization
public:
    int dp[100001];
    int func(vector<int>&h, int ind, int k){
        if(ind==h.size()-1) return 0;
        else if(ind>=h.size()) return 1e7;
        int ans = INT_MAX;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind+1;i<ind+k+1&&i<h.size();i++){
            int check = abs(h[i]-h[ind])+func(h,i,k);
            ans = min(ans,check);
        }
        return dp[ind] = ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        memset(dp,-1,sizeof(dp)); 
        return func(height,0,k);
    }
};