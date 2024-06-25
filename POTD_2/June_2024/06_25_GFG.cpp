#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        vector<vector<int>> v(mat.size(),vector<int>(mat[0].size(),0));
        k = k % mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=k;j<mat[0].size();j++){
                v[i][j-k] = mat[i][j];
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<k;j++){
                v[i][mat[0].size()-k+j] = mat[i][j];
            }
        }
        return v;
    }
};