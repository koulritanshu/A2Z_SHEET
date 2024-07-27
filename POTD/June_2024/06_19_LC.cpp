#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool func(vector<int>&curr, int m, int k, int mid){
        int cnt = 0;
        int tot = 0;
        for(int i=0;i<curr.size();i++){
            if(curr[i]<=mid) cnt++;
            else{
                cnt = 0;
            }
            if(cnt==k){
                cnt = 0;
                tot++;
                if(tot == m) return true;
            }
        }
        return (tot==m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)((long long)m*(long long)k) > (long long)bloomDay.size()) return -1;
        int st = INT_MAX;
        int ed = 0; 
        for(auto &i:bloomDay) {ed = max(ed,i); st = min(st,i);}
        int ans = INT_MAX;
        while(st <= ed){
            int mid = st + (ed - st)/2;
            if(func(bloomDay, m, k, mid)){
                ans = mid;
                ed = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};