#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestNumber(int s, int d) {
        string ans = "";
        int maxi = 9*d;
        if(s>maxi) return "-1";
        for(int i=0;i<d;i++){
            ans += '9';
        }
        int extra = maxi-s;
        for(int i=0;i<ans.size();i++){
            int curr = ans[i]-'0';
            if(extra>=9){
                if(i!=0){
                    ans[i]='0';
                    extra -= 9;
                }
                else{
                    ans[i]='1';
                    extra-=8;
                }
            }
            else{
                ans[i]=('0'+(9-extra));
                break;
            }
        }
        return ans;
    }
};