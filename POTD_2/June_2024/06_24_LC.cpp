#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipsInWindow = 0;
        int flipCount = 0;
        vector<int> flipped(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                // decreasing flipsInWindow
                if(flipped[i-k]){
                    flipsInWindow--;
                }
            }
            if(nums[i]==0){
                // check if flips from the window make it 1 or not
                if(flipsInWindow%2==0){
                    flipsInWindow++;
                    flipCount++;
                    flipped[i] = 1;
                    if((i+k-1)>=nums.size()) return -1;
                }
            }
            else if(nums[i]==1){
                if(flipsInWindow%2==1){
                    flipsInWindow++;
                    flipCount++;
                    flipped[i] = 1;
                    if((i+k-1)>=nums.size()) return -1;
                }
            }
        }
        return flipCount;
    }
};

class BetterSpace {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipsInWindow = 0;
        int flipCount = 0;
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                // decreasing flipsInWindow
                if(nums[i-k]==2){
                    flipsInWindow--;
                }
            }
            if(nums[i]==0){
                // check if flips from the window make it 1 or not
                if(flipsInWindow%2==0){
                    flipsInWindow++;
                    flipCount++;
                    nums[i] = 2;
                    if((i+k-1)>=nums.size()) return -1;
                }
            }
            else if(nums[i]==1){
                if(flipsInWindow%2==1){
                    flipsInWindow++;
                    flipCount++;
                    nums[i] = 2;
                    if((i+k-1)>=nums.size()) return -1;
                }
            }
        }
        return flipCount;
    }
};