#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        vector<int> dp(arr.size(),1);
        vector<int> cnt(arr.size(),1);
        int mx = 1;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(dp[i]==1+dp[j]){
                        cnt[i]+=cnt[j];
                    }
                    else if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    mx = max(mx,dp[i]);
                }
            }
        }
        for(int i=0;i<arr.size();i++){
            if(dp[i]==mx){
                ans += cnt[i];
            }
        }
        return ans;
    }
};