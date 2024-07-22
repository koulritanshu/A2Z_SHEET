#include <bits/stdc++.h>
using namespace std;

class printingLIS {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n+1,1);
        vector<int> hash(n+1,0);
        for(int i=0;i<=n;i++){
            hash[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(dp[i]<1+dp[j]){
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                    }
                }
            }
        }
        int endd = -1;
        int anss = -1;
        for(int i=0;i<=n;i++){
            if(dp[i]>anss){
                anss = dp[i];
                endd=i;
            }
        }
        vector<int> ans;
        while(hash[endd]!=endd){
            ans.push_back(arr[endd]);
            endd = hash[endd];
        }
        ans.push_back(arr[endd]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};