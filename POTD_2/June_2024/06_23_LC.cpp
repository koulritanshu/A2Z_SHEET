#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mp;
        int i=0,j=0,ans=1;
        int mx = 0,mn = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            mx = prev(mp.end())->first;
            mn = mp.begin()->first;
            while((mx-mn)>limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
                mn = mp.begin()->first;
                mx = prev(mp.end())->first;
            }
            if(mx-mn<=limit){
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};