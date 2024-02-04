#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> ft;
        for(int i=0;i<t.size();i++){
            ft[t[i]]++;
        }
        map<char,int> fs;
        int matchcount = 0;
        int i = 0, j = 0;
        int ans = INT_MAX;
        int st = -1;
        int ed = -1;
        while(j<s.size()){
            fs[s[j]]++;
            if(ft.find(s[j])!=ft.end() && fs[s[j]]<=ft[s[j]]){
                matchcount++;
            }
            while(matchcount==t.size()){
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    st=i;
                    ed=j;
                }
                fs[s[i]]--;
                if(ft.find(s[i])!=ft.end() && fs[s[i]]<ft[s[i]]){
                    matchcount--;
                }
                i++;
            }
            j++;
        }
        if(st==-1) return "";
        string an = "";
        for(int i=st;i<=ed;i++) an+=s[i];
        return an;
    }
};