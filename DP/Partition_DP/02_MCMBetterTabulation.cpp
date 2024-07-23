#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution{
public:
    // int dp[102][102];
    // int func(int i,int j, int arr[]){
    //     if(i==j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int mini = 1e9;
    //     for(int k=i;k<j;k++){
    //         int steps = func(i,k,arr) + func(k+1,j,arr);
    //         steps += arr[i-1]*arr[k]*arr[j];
    //         mini = min(mini,steps);
    //     }
    //     return dp[i][j] = mini;
    // }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini = 1e9; 
                for(int k=j-1;k>=i;k--){
                    int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    mini = min(mini,steps);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[1][N-1];
    }
};