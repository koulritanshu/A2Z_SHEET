#include <bits/stdc++.h>
using namespace std;

// Almost same as subset with sum K

class topDown {
public:
    int mod = 1e9+7;
    int func(int ind,int sum,vector<int>&arr, vector<vector<int>>&dp){
        if(ind==-1){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum]%mod;
        int notTake = func(ind-1,sum,arr,dp)%mod;
        int take=0;
        if(arr[ind]<=sum){
            take = func(ind-1,sum-arr[ind],arr,dp)%mod;
        }
        return dp[ind][sum]=(take+notTake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int total_sum = 0;
        for(int i=0;i<n;i++){
            total_sum += arr[i];
        }
        if((total_sum+d)%2) return 0;
        int x = (total_sum + d)/2;
        // (10 + 5)/2 = 7
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        return func(n-1,x,arr,dp)%mod;
    }
};