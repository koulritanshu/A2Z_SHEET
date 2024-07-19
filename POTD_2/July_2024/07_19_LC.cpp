#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // observation: there can be atmax only 1 lucky number
        int row=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            int c = matrix[i][0];
            for(int j=0;j<matrix[0].size();j++){
                c = min(c,matrix[i][j]);
            }
            row=max(row,c);
        }
        int col=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            int c = matrix[0][i];
            for(int j=0;j<matrix.size();j++){
                c=max(c,matrix[j][i]);
            }
            col=min(col,c);
        }
        if(row==col) return {row};
        return {};
    }
};