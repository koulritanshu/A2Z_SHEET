#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void func(vector<string>&curr, vector<vector<string>>&ans, string &s, int i){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int x=i;x<s.size();x++){
            temp += s[x];
            if(check(s,i,x)){
                curr.push_back(temp);
                func(curr,ans,s,x+1);
                curr.pop_back();
            }
        }        
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        func(v,ans,s,0);
        return ans;
    }
};