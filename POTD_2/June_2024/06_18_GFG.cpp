#include <bits/stdc++.h>
using namespace std;


// consider rectangle placed in such a way that the diagonal lies on the diameter
// then all of its edges will be within the rectangle only if [length(diagonal) <= length(diameter)]
// we will use simple distance formula to check this 

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int cnt = 0;
        int check = 4*r*r;
        for(int i=1;i<2*r;i++){
            for(int j=1;j<2*r;j++){
                int curr = pow(i,2) + pow(j,2);
                if(curr<=check) cnt++;
            }
        }
        return cnt;
    }
};