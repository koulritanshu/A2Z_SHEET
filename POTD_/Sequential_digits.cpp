#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void func(vector<int>&v, string x){
        v.push_back(stoi(x));
        for(char t=x[1]+1;t<='9';t++){
            x += t;
            v.push_back(stoi(x));
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        func(v,"12");
        func(v,"23");
        func(v,"34");
        func(v,"45");
        func(v,"56");
        func(v,"67");
        func(v,"78");
        v.push_back(89);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(v[i]>=low&&v[i]<=high){
                ans.push_back(v[i]);
            }
        } 
        sort(ans.begin(),ans.end());
        return ans;
    }
};