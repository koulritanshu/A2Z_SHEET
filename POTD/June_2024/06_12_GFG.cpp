#include <bits/stdc++.h>
using namespace std;

// given n, calculate count of numbers having 4 as a digit from 1 to n

class Solution {
  public:
    int countNumberswith4(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            bool present = false;
            int num = i;
            while(num){
                int dig = num%10;
                num /= 10;
                if(dig==4){
                    present = true;
                    break;
                }
            }
            if(present) cnt++;
        }
        return cnt;
    }
};