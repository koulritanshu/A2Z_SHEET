#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<string,int>&first, pair<string,int> &second){
        return first.second>second.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> vp;
        for(int i=0;i<names.size();i++){
            vp.push_back({names[i],heights[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<string> ans;
        for(auto &i:vp) ans.push_back(i.first);
        return ans;
    }
};