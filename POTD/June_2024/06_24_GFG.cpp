#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // 1+1 -> 1 times
        // 1+2 -> 2 times
        // 1+3 -> 3 times
        // 1+n -> n times
        // 1+n+1 -> n-1 times
        // 1+n+1+1 -> n-2 times
        // 1+n+n-1 -> n - (n-1) times
        if(q > (n+n) || q <= 1) return 0;
        q-=1;
        if(q<=n) return q;
        q-=n;
        return n-q;
    }
};