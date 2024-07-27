#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ind1 = 0, ind2 = 0;
        vector<int> ans;
        while(ind1<nums1.size() && ind2<nums2.size()){
            if(nums1[ind1]==nums2[ind2]){
                ans.push_back(nums1[ind1]);
                ind1++;
                ind2++;
            }
            else if(nums1[ind1]>nums2[ind2]){
                ind2++;
            }
            else{
                ind1++;
            }
        }
        return ans;
    }
};