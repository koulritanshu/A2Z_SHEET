#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    long long m(long long a, long long b){
        return ((a%mod)*(b%mod))%mod;
    }
    long long int findMaxProduct(vector<int>& arr) {
        long long ans = arr[0];
        bool zeroPresent = false;
        long long multi = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zeroPresent = true;
                ans = max((long long)0,multi);
            }
            else{
                multi = m(multi,(long long)arr[i]);
                ans = max(multi,(long long)arr[i]);
            }
        }
        long long maxiNeg = INT_MIN;
        for(auto &i:arr){
            if(i<0)
            maxiNeg = max(maxiNeg,(long long)i);
        }
        multi = multi / maxiNeg;
        // cout << "multi = " << multi << endl;
        return max(ans,multi);
    }
};
