#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int dp[505];
    // int func(vector<int>&arr, int i,int k){
    //     if(i>=arr.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mxi = 0;
    //     int mx = arr[i];
    //     int cnt=0;
    //     for(int j=i;j<arr.size()&&cnt<k;j++){
    //         mx = max(mx,arr[j]);
    //         int sum = mx*(j-i+1);
    //         mxi = max(mxi,sum+func(arr,j+1,k));
    //         cnt++;
    //     }
    //     return dp[i] = mxi;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // memset(dp,-1,sizeof(dp));
        // return func(arr,0,k);
        vector<int> dp(arr.size()+1,0);
        for(int i=arr.size()-1;i>=0;i--){
            int cnt=0;
            int mx = arr[i];
            int mxi=0;
            for(int j=i;j<arr.size()&&cnt<k;j++,cnt++){
                mx = max(mx,arr[j]);
                int sum = mx*(j-i+1);
                mxi=max(mxi,sum+dp[j+1]);
            }
            dp[i] = mxi;
        }
        return dp[0];
    }
};