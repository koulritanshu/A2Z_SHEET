#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int i=0,j=0,curr=0;
        int ans2 = 0;
        while(j<customers.size()){
            if((j-i+1)>minutes){
                if(grumpy[i]){
                    curr -= customers[i];
                }
                i++;
            }
            if(grumpy[j]==1){
                curr += customers[j];
                ans2 = max(ans2,curr);
            }
            else ans+=customers[j];
            j++;
        }
        return ans + ans2;
    }
};