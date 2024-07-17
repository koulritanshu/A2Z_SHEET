#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left=0,right=arr.size()-1;
        while(left<right){
            while(left<right && arr[left]==0) left++;
            while(left<right && arr[right]==1) right--;
            if(left<right){
                arr[left]=0;
                arr[right]=1;
                left++;
                right--;
            }
        }
    }
};