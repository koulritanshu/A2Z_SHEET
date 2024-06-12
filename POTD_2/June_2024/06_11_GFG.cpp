#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i]-brr[i],i});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        // for(int i=0;i<n;i++){
        //     cout << vp[i].first << " " << vp[i].second << endl;
        // }
        long long ans = 0;
        int i=0,j=n-1;
        int st_ind = -1;
        for(int i=0;i<n;i++){
            if(vp[i].first>=0 && x>0){
                ans += arr[vp[i].second];
                x--;
            }
            else{
                st_ind = i;
                break;
            }
        }
        // cout << "Ans = " << ans << endl;
        if(st_ind==-1){
            return ans;
        }
        int ed_ind = -1;
        for(int i=n-1;i>=st_ind;i--){
            if(vp[i].first<=0 && y>0){
                ans += brr[vp[i].second];
                y--;
            }
            else{
                ed_ind = i;
                break;
            }
        }
        if(ed_ind==-1) return ans;
        // cout << "ans = "<< ans << endl;
        for(int i=st_ind;i<=ed_ind;i++){
            if(x){
                ans += arr[vp[i].second];
                x--;
            }
            else if(y){
                ans += brr[vp[i].second];
                y--;
            }
        }
        return ans;
    }
};