#include <bits/stdc++.h>
using namespace std;

// Same as previous question
// The only difference is in the previous question max transactions possible were 2
// Here the max possible transactions are kk
// Just replace size of vector rest everything will remain same

class Solution {
public:
    int maxProfit(int kk, vector<int>& prices) {
        vector<vector<int>> pre(2,vector<int>(kk+4,0));
        vector<vector<int>> curr(2,vector<int>(kk+4,0));
        for(int j=0;j<=1;j++){
            for(int k=0;k<=kk;k++){
                pre[j][k]=0;
            }
        }
        pre[0][2]=pre[1][2]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<kk;k++){
                    int ans;
                    if(j==1){
                        ans = max(prices[i]+pre[0][k+1],pre[j][k]);
                    }
                    else{
                        ans = max(-prices[i]+pre[1][k],pre[j][k]);
                    }
                    curr[j][k] = ans;
                }
            }
            pre=curr;
        }
        return pre[0][0];
    }
};