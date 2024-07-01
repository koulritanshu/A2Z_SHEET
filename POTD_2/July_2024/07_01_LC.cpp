#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                if(i+1<arr.size() && i+2<arr.size()){
                    if(arr[i+1]%2 && arr[i+2]%2) return true;
                }
            }
        }
        return false;
    }
};