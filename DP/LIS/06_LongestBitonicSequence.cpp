#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fromStart(int n, vector<int>&arr)
    {
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return dp;
    }
    vector<int> fromEnd(int n, vector<int>&arr)
    {
        vector<int> dp(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return dp;
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> p = fromStart(n,nums);
        vector<int> e = fromEnd(n,nums);
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(p[i]>1 && e[i]>1){
                ans = max(ans,p[i]+e[i]-1);
            }
        }
        return ans;
    }
};