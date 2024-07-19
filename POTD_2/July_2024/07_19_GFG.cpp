#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void merge(vector<pair<int,int>>&vp, vector<int>&ans, int s, int mid,int e){
        vector<pair<int,int>> temp(e-s+1);
        int ind1 = s, ind2 = mid+1;
        int k=0;
        while(ind1<=mid && ind2<=e){
            if(vp[ind1].first <= vp[ind2].first){
                temp[k] = vp[ind2];
                k++;
                ind2++;
            }
            else{
                ans[vp[ind1].second] += e-ind2+1;
                temp[k] = vp[ind1];
                k++;
                ind1++;
            }
        }
        while(ind2<=e){
            temp[k] = vp[ind2];
            k++;
            ind2++;
        }
        while(ind1<=mid){
            temp[k] = vp[ind1];
            k++;
            ind1++;
        }
        for(int i=0;i<e-s+1;i++){
            vp[i+s] = temp[i];
        }
    }
    void mergeSort(vector<pair<int,int>>&vp, vector<int>&ans, int s, int e){
        if(s>=e) return;
        int mid = s + (e - s)/2;
        mergeSort(vp,ans,s,mid);
        mergeSort(vp,ans,mid+1,e);
        merge(vp,ans,s,mid,e);
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n = arr.size();
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            vp[i] = {arr[i],i};
        }
        vector<int> ans(n,0);
        mergeSort(vp,ans,0,arr.size()-1);
        return ans;
    }
};