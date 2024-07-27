#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int maxi = -1;
        for(int i=0;i<seats.size();i++){
            maxi = max(maxi,max(seats[i],students[i]));
        }
        vector<int> v(maxi+1,0);
        for(int i=0;i<seats.size();i++){
            v[seats[i]-1]++;
            v[students[i]-1]--;
        }
        int ans = 0;
        int used = 0;
        for(auto &i:v){
            ans += abs(used);
            used += i;
        }
        return ans;
    }
};