#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        int curr_count = 0;
        string ans = "";
        int index = -1;
        for(int i=0;i<s.size();i++){
            if(index!=-1){
                ans += s[i];
                continue;
            }
            else{
                if(s[i]==ch){
                    curr_count++;
                    if(curr_count==count){
                        index=i;
                    }
                }
            }
        }
        if(index==-1) return "";
        return ans;
    }
};