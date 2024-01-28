#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28
// https://www.youtube.com/watch?v=xaL5rO_o7kw

class Brute
{
public:
    int Sum(vector<vector<int>> &matrix, int rowStart, int rowSize, int colStart, int colSize)
    {
        int sum = 0;
        for (int i = rowStart; i <= rowStart + rowSize; i++)
        {
            for (int j = colStart; j <= colStart + colSize; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int rowStart = 0; rowStart < matrix.size(); rowStart++)
        {
            for (int rowSize = 1; rowStart + rowSize < matrix.size(); rowSize++)
            {
                for (int colStart = 0; colStart < matrix[0].size(); colStart++)
                {
                    for (int colSize = 1; colStart + colSize < matrix[0].size(); colSize++)
                    {
                        int sum = Sum(matrix, rowStart, rowSize, colStart, colSize);
                    }
                }
            }
        }
    }
};

// Using Prefix Sum
class Solution1
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int ans = 0;
        for (int colStart = 0; colStart < matrix[0].size(); colStart++)
        {
            for (int colEnd = colStart; colEnd < matrix[0].size(); colEnd++)
            {
                for (int rowStart = 0; rowStart < matrix.size(); rowStart++)
                {
                    int curr_sum = 0;
                    for (int rowEnd = rowStart; rowEnd < matrix.size(); rowEnd++)
                    {
                        curr_sum += matrix[rowEnd][colEnd];
                        if (colStart)
                        {
                            curr_sum -= matrix[rowEnd][colStart - 1];
                        }
                        if (curr_sum == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// O(n^3)
class Optimized
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int ans = 0;
        for (int colStart = 0; colStart < matrix[0].size(); colStart++)
        {
            for (int colEnd = colStart; colEnd < matrix[0].size(); colEnd++)
            {
                int curr_sum = 0;
                unordered_map<int, int> mp;
                mp[0] = 1;
                for (int row = 0; row < matrix.size(); row++)
                {
                    curr_sum += matrix[row][colEnd];
                    if (colStart)
                    {
                        curr_sum -= matrix[row][colStart - 1];
                    }
                    ans += mp[curr_sum - target];
                    mp[curr_sum]++;
                }
            }
        }
        return ans;
    }
};