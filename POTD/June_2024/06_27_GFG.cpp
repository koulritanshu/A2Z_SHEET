#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>>& mat) {
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(i-1>=0 && j-1>=0){
                if(mat[i][j]!=mat[i-1][j-1]){
                    return false;
                }
            }        
        }
    }
    return true;
}