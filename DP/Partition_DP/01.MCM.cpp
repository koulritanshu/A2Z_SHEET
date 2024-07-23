#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=-UPo_dzBw1c&t=529s


class Memoization{
public:
    int dp[102][102];
    int func(int i,int j, int arr[]){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k=i;k<j;k++){
            int steps = func(i,k,arr) + func(k+1,j,arr);
            steps += arr[i-1]*arr[k]*arr[j];
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return func(1,N-1,arr);
    }
};

class Memoization2{
public:
    // if you want to select i, i+1 as matrix coordinates instead of (i-1,i)
    int dp[102][102];
    int func(int i,int j, int arr[]){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k=i;k<j;k++){
            int steps = func(i,k,arr) + func(k+1,j,arr);
            steps += arr[i]*arr[k+1]*arr[j+1];
            mini = min(mini,steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return func(0,N-2,arr);
    }
};

class Tabulation
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> ans(N, vector<int>(N, 0));
        for (int diff = 2; diff < N; diff++)
        {
            for (int i = 0; i < N; i++)
            {
                int j = i + diff;
                if (j >= N)
                    break;
                ans[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j] + (arr[i] * arr[j] * arr[k]));
                }
            }
        }  
        return ans[0][N - 1];
    }
};