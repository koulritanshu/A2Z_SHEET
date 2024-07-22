#include <bits/stdc++.h>
using namespace std;

class BinarySearchApproach
{
public:
    void findInd(vector<int> &v,int k){
        int st = 0, ed = v.size()-1;
        int ans=-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(v[mid]<=k){
                if(v[mid]==k) return;
                ans = mid;
                st = mid+1;
            }
            else{
                ed = mid-1;
            }
        }
        v[ans+1] = k;
    }
    int longestSubsequence(int n, int arr[])
    {
        vector<int> ans;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(ans.size() == 0 || arr[i]>ans[ans.size()-1]){
                ans.push_back(arr[i]);
            }
            else{
                findInd(ans,arr[i]);
            }
        }
        return ans.size();
    }
};