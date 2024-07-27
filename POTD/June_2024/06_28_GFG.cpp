#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<int>&a){
        int i=0, j = a.size()-1;
        while(i<j){
            if(a[i]!=a[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int checkRows(vector<vector<int>> &arr){
        for(int i=0;i<arr.size();i++){
            if(check(arr[i])){
                return i;
            }
        }
        return -1;
    }

    int checkCols(vector<vector<int>> &arr){
        for(int col=0;col<arr[0].size();col++){
            int i = 0, j = arr.size()-1;
            bool found = true;
            while(i<j){
                if(arr[i][col]!=arr[j][col]){
                    found = false;
                    break;
                }
                i++;
                j--;
            }
            if(found) return col;
        }
        return -1;
    }

    string pattern(vector<vector<int>> &arr) {
        int row = checkRows(arr);
        if(row!=-1){
            string ans = "";
            ans += to_string(row);
            ans += ' ';
            ans += 'R';
            return ans;
        }
        int col = checkCols(arr);
        if(col!=-1){
            string ans = "";
            ans += to_string(col);
            ans += ' ';
            ans += 'C';
            return ans;
        }
        return "-1";
    }
};