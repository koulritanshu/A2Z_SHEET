#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long convert(string num){
        if(num=="") return -1;
        long long x = 0;
        for(int i=0;i<num.size();i++){
            x = x*10 + (num[i]-'0');
        }
        return x;
    }    
    long long ExtractNumber(string sentence) {
        long long ans = -1;
        string num = "";
        bool ninePresent = false;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]>='0' && sentence[i]<='9'){
                num += sentence[i];
                if(sentence[i]=='9'){
                    ninePresent = true;
                }
            }
            else{
                if(ninePresent){
                    ninePresent = false;
                    num = "";
                }
                else{
                    ans = max(ans,convert(num));
                    num = "";
                }
            }
        }
        return ans;
    }
};