#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<bool> curr(sum+1,false);
        vector<bool> prev(sum+1,false);
        prev[0]=true;
        curr[0]=true;
        for(int i=0;i<arr.size();i++){
            if(prev[sum]) return true;
            if(arr[i]>sum) continue;
            for(int j=0;j<=sum;j++){
                if(prev[j])
                if(j+arr[i]<=sum)
                curr[j+arr[i]]=true;
            }
            prev=curr;
        }
        return curr[sum];
    }
};

class BottomUp{
    // Tabulation   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,false));
        dp[0][0] = true;
        if(arr[0]<=sum)
        dp[0][arr[0]]=true;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=sum)
            dp[i][arr[i]]=1;
            for(int j=0;j<=sum;j++){
                if(!dp[i-1][j]) continue;
                dp[i][j] = 1;
                if(j+arr[i]<=sum)
                dp[i][j+arr[i]]=1;
            }
        }
        return dp[arr.size()-1][sum];
    }
};

class TopDown{   
    // Memoization
public:
    int dp[101][10001];
    bool func(vector<int>&arr,int sum, int ind){
        if(sum == 0) return true;
        if(ind==arr.size()) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        return dp[ind][sum] = (func(arr,sum-arr[ind],ind+1)||func(arr,sum,ind+1));
    }
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp,-1,sizeof(dp));
        return func(arr,sum,0);
    }
};