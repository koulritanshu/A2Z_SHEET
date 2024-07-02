#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=-UPo_dzBw1c&t=529s

class Solution
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