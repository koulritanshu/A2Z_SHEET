#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/height-checker/description/

// Example 1:
// Input: heights = [1,1,4,2,1,3]
// Output: 3
// Explanation: 
// heights:  [1,1,4,2,1,3]
// expected: [1,1,1,2,3,4]
// Indices 2, 4, and 5 do not match.

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        auto x = heights;
        sort(x.begin(), x.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (x[i] != heights[i])
                cnt++;
        }
        return cnt;
    }
};