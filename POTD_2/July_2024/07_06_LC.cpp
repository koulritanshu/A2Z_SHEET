#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % (n + n - 2);
        int maxi = n + n - 2;
        int mid = maxi/2;
        if(time<=mid){
            return time+1;
        }
        else{
            time -= n;
            return mid-time;
        }
    }
};