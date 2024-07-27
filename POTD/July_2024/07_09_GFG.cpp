#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(),arr.end());
        // -10 -10 -9 -9 0 3 5 6 8 9 10
        int diff = INT_MAX;
        int ans = -1;
        for(int i=0;i<arr.size()-2;i++){
            if(i!=0 && arr[i]==arr[i-1]) continue;
            int st = i+1;
            int ed = arr.size()-1;
            while(st<ed){
                int curr = arr[i] + arr[st] + arr[ed];
                int diffc = abs(target - curr);
                if(diffc==0) return curr;
                if(diffc<diff){
                    ans = curr;
                    diff = diffc;
                }
                else if(diffc==diff){
                    ans = max(ans,curr);
                }
                if(target<curr) ed--;
                else st++;
            }
        }
        return ans;
    }
};