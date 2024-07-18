#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization{
public:
    int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int> pre(sum+1,0);
	    vector<int> curr(sum+1,0);
	    if(arr[0]==0){
	        pre[0]=2;
	    }
	    else{
	        pre[0]=1;
	        if(arr[0]<=sum){
	            pre[arr[0]]=1;
	        }
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=sum;j++){
	            int notTake = pre[j];
	            int take=0;
	            if(arr[i]<=j){
	                take=pre[j-arr[i]];
	            }
	            curr[j] = (notTake+take)%mod;
	        }
	        pre=curr;
	    }
	    return pre[sum]%mod;
	}
};

class Tabulation{
public:
    int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp = vector<vector<int>>(n,vector<int>(sum+1,0));
	    if(arr[0]==0) dp[0][0]=2; // if array contains zeroes
	    else{
	        dp[0][0]=1;
	        if(arr[0]<=sum) dp[0][arr[0]]=1;
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<=sum;j++){
	            int notTake = dp[i-1][j];
	            int take=0;
	            if(arr[i]<=j){
	                take=dp[i-1][j-arr[i]];
	            }
	            dp[i][j] = (notTake+take)%mod;
	        }
	    }
	    return dp[n-1][sum]%mod;
	}
};

class memo{
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int func(int arr[],int ind,int sum){
        if(ind==-1){
            if(sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ans = func(arr,ind-1,sum);
        if(arr[ind]<=sum){
            ans = ((ans%mod)+(func(arr,ind-1,sum-arr[ind])%mod))%mod;
        }
        return dp[ind][sum]=ans%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
	    dp = vector<vector<int>>(n,vector<int>(sum+1,-1));
	    return func(arr,n-1,sum)%mod;
	}
};