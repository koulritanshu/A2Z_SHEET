#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<char,int>&a, pair<char,int>&b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    string frequencySort(string s) {
        vector<pair<char,int>> vp;
        for(int i=0;i<26;i++){
            vp.push_back({'a'+i,0});
        }
        for(int i=0;i<26;i++){
            vp.push_back({'A'+i,0});
        }
        for(int x='0';x<='9';x++){
            vp.push_back({x,0});
        }
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z')
            vp[s[i]-'a'].second+=1;
            else if(s[i]>='A'&&s[i]<='Z')
            vp[s[i]-'A'+26].second+=1;
            else
            vp[s[i]-'0'+52].second+=1;
        }
        sort(vp.begin(),vp.end(),cmp);
        string ans = "";
        for(int i=0;i<vp.size();i++){
            if(vp[i].second==0) break;
            for(int j=0;j<vp[i].second;j++){
                ans+=vp[i].first;
            }
        }
        return ans;
    }
};