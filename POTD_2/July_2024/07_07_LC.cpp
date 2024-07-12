#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int emptyBottles = 0;
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles == 0) return 0;
        int ans = numBottles;
        emptyBottles += numBottles;
        if(emptyBottles < numExchange) return ans;
        int fullBottles = emptyBottles / numExchange;
        emptyBottles -= (fullBottles*numExchange);
        if(fullBottles == 0) return ans;
        return ans + numWaterBottles(fullBottles,numExchange);
    }
};