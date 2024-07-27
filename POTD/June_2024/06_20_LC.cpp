#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>&v, int m, int mid){
        int x = m;
        int pre = v[0];
        x--;
        for(int i=1;i<v.size();i++){
            if(x==0) return true;
            if((v[i]-pre)>=mid){
                pre=v[i];
                x--;
            }
        }
        return (x==0);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int st = INT_MAX, ed = -1;
        ed = position[position.size()-1]-position[0];
        for(int i=1;i<position.size();i++){
            st = min(st,position[i]-position[i-1]);
        }
        if(m==position.size()) return st;
        int ans = 0;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(check(position,m,mid)){
                ans = mid;
                st = mid+1;
            }
            else{
                ed = mid-1;
            }
        }
        return ans;
    }
};