#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi[prices.size()];
        maxi[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            maxi[i] = max(maxi[i+1],prices[i]);
        }
        int ans = 0;
        for(int i=0;i<prices.size()-1;i++){
            ans = max(ans,maxi[i+1]-prices[i]);
        }
        return ans;
    }
};

class SpaceOptimized {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int maxi = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            ans = max(ans,maxi-prices[i]);
            maxi = max(maxi,prices[i]);
        }
        return ans;
    }
};