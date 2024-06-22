#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        for (int via = 0; via < matrix.size(); via++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix.size(); j++)
                {
                    if (matrix[i][via] != -1 && matrix[via][j] != -1)
                    {
                        if (matrix[i][j] == -1)
                            matrix[i][j] = INT_MAX;
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }
    }
    // if cost of any node to itself that matrix[i][i]<0, that means 
    // negative cycle exists in the graph
};