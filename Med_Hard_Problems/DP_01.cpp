#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    unordered_map<int,int> mp;
    long long func(vector<int>&power, long long ind,vector<long long>&dp){
        if(ind>=power.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long ans = func(power,ind+1,dp);
        long long curr = ((long long)mp[power[ind]])*(long long)power[ind];
        long long next = ind+1;
        if(next<power.size() && ((power[next]-power[ind])>2)){
            ans = max(ans,curr+func(power,next,dp));
        }
        else{
            next++;
            if(next<power.size() && ((power[next]-power[ind])>2)){
                ans = max(ans,curr+func(power,next,dp));
            }   
            else{
                ans = max(ans,curr+func(power,next+1,dp));
            } 
        }
        return dp[ind] = ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        for(int i=0;i<power.size();i++){
            mp[power[i]]++;
        }
        vector<int> v;
        v.push_back(power[0]);
        for(int i=1;i<power.size();i++){
            if(power[i]!=v[v.size()-1]){
                v.push_back(power[i]);
            }
        }
        vector<long long int> dp(v.size()+1,-1);
        return func(v,0,dp);
    }
};