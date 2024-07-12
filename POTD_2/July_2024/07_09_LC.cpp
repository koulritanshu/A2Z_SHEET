#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr_time = customers[0][0];
        double ans = 0;
        for(int i=0;i<customers.size();i++){
            if(curr_time<customers[i][0]) curr_time=customers[i][0];
            int eddi = curr_time + customers[i][1];
            curr_time = eddi;
            int waiting = eddi - customers[i][0];
            ans += (double)waiting;
        }
        ans = ans / (double)(customers.size());
        return ans;
    }
};