#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/?envType=daily-question&envId=2024-05-30

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        vector<int> pre(arr.size() + 1, 0);
        for (int i = 1; i < arr.size() + 1; i++)
        {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        int steps = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (pre[i] == pre[j + 1])
                    steps += (j - i);
            }
        }
        return steps;
    }
};