#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int cnt = 0;
        int xx[4] = {1,-1,0,0};
        int yy[4] = {0,0,1,-1};
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<4;k++){
                        int nx = i+xx[k];
                        int ny = j+yy[k];
                        if(nx>=0&&nx<matrix.size()&&ny>=0&&ny<matrix[0].size()&&matrix[nx][ny]){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};