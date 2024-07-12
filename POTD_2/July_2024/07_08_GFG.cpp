#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // 2 3 4 5 1
    // 0 1 2 3 4
    int search(vector<int>& arr, int key) {
        int st = 0, ed = arr.size()-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>=arr[st]){
                // 5 6 7 8 1 2 3 4
                // 0 1 2 3 4 5 6 7
                // sorted part left to mid
                if(key>=arr[st] && key <= arr[mid]){
                    ed = mid-1;
                }
                else{
                    st = mid + 1;
                }
            }
            else {
                // sorted part mid to right
                // 6 7 8 1 2 3 4 5
                if(key>=arr[mid] && key <= arr[ed]){
                    st = mid + 1;
                }
                else{
                    ed = mid - 1;
                }
            }
        }
        return -1;
    }
};