#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int MOD = 1e9 + 7;
    int padovanSequence(int n)
    {
        int a = 1 , b = 1, c = 2;
        if(n<=2) return 1;
        for(int i=4;i<=n;i++){
            int d = ((a%MOD)+b%(MOD))%MOD;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
    
};