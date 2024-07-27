#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long area(long long p[], long long q[], long long r[]){
        return abs(p[0]*(q[1]-r[1])+q[0]*(r[1]-p[1])+r[0]*(p[1]-q[1]));
    }
    
    long long b_point(long long p[], long long q[]){
        return __gcd(abs(p[0]-q[0]),abs(p[1]-q[1]));
    }
    
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // calculate 2*area using determinant method
        long long ar_2 = area(p,q,r);
        // calculate boundary points using gcd 
        long long boundary_points = b_point(p,q)+b_point(q,r)+b_point(r,p);
        // Use Pick's theorem to calculate internal points
        // I = (Ar_2 - boundary_points + 2)/2
        
        long long internal_points = (ar_2 - boundary_points + 2)/2;
        return internal_points;
    }
};