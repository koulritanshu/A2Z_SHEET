#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> vp;
        for(auto i:mp){
            vp.push_back({i.second,i.first});
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<vp.size();i++){
            if(vp[i].first<=k){
                k-=vp[i].first;
            }
            else{
                return vp.size()-i;
            }
        }
        return 0;
    }
};