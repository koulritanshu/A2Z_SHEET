#include <bits/stdc++.h>
using namespace std;

class SpaceOptimized {
public:
    int lcs(string text1, string text2) {
        vector<int> pre(text2.size()+1,0);
        vector<int> curr(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1+pre[j-1];
                }
                else{
                    curr[j]=max(pre[j],curr[j-1]);
                }
            }
            pre=curr;
        }
        return pre[text2.size()];
    }
    int longestPalindromeSubseq(string s) {
        string other = s;
        reverse(other.begin(),other.end());
        return lcs(s,other);
    }
};