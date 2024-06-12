#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0, ed = nums.size()-1,mid = 0;
        while(mid <= ed){
            if(nums[mid]==0){
                swap(nums[st],nums[mid]);
                st++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[ed],nums[mid]);
                ed--;
            }
            else if(nums[mid]==1)mid++;
        }
    }
};