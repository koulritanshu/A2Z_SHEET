#include <bits/stdc++.h>
using namespace std;

class SpaceOptimization {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        if(n==1) return 0;
        int a = 0;
        int b = abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int one = abs(height[i]-height[i-1])+b;
            int other = abs(height[i]-height[i-2])+a;
            int c = min(one,other);
            a = b;
            b = c;
        }
        return b;
    }
};

class BottomUp {
    // Tabulation
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int one = abs(height[i]-height[i-1])+dp[i-1];
            int other = abs(height[i]-height[i-2])+dp[i-2];
            dp[i] = min(one,other);
        }
        return dp[n-1];
    }
};

class TopDown {
public:
    // Memoization
    int dp[100009];
    int func(vector<int>&height,int ind){
        if(ind==height.size()-1) return 0;
        else if(ind>=height.size()) return 1e6;
        if(dp[ind]!=-1) return dp[ind];
        int ans = abs(height[ind+1]-height[ind])+func(height,ind+1);
        if(ind+2<height.size()){
            ans = min(ans,abs(height[ind+2]-height[ind])+func(height,ind+2));
        }
        return dp[ind] = ans;
    }    
    int minimumEnergy(vector<int>& height, int n) {
        memset(dp,-1,sizeof(dp));
        return func(height,0);
    }
};