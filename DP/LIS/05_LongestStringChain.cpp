#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string &a, string &b){
        if(b.size()!=a.size()-1) return false;
        int ind1 = 0,ind2=0;
        while(ind1<a.size() && ind2<b.size()){
            if(a[ind1]==b[ind2]){
                ind1++;
                ind2++;
            }
            else{
                ind1++;
            }
        }
        return (ind2==b.size());
    }
    int func(int n, vector<string>& arr) {
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string a = arr[i];
                string b = arr[j];
                if(check(a,b)){
                    if(dp[i]<1+dp[j]){
                        dp[i] = 1+dp[j];
                    }
                }
            }
        }
        int anss = -1;
        for(int i=0;i<=n;i++){
            if(dp[i]>anss){
                anss = dp[i];
            }
        }
        return anss;
    }
    static bool cmp(string &a, string &b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        return func(words.size(),words);
    }
};