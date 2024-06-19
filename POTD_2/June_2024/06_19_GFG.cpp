#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double maxVolume(double P, double A) {
        double l = (P - sqrt(P*P - 24*A))/12;
        double h = P/4 - 2*l;
        
        double vol = l*l*h;
        return vol;
    }
};

// For maximum volume, l = b
// 2l + h = p/4
// a/2 = l^2 + lh + lh

// a/2 = l^2 + 2lh

// 2l + a/4l - l/2 = p/4

// 8l^2 + a - 2l^2 = pl

// 6l^2 -pl + a = 0

// l = (p - sqrt(p^2 - 24a))/12 