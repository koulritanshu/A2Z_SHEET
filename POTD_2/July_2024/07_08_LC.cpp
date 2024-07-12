#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int st = 0;
        while(v.size() > 1){
            int x = v.size();
            v.erase(v.begin()+((st+k-1)%v.size()));
            st = (st+k-1)%x;
        }
        return v[0];
    }
};