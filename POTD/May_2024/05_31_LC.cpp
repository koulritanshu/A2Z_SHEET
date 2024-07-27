#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> answer;
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr = xorr ^ nums[i];
        }
        int ones = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((1 << i) & xorr)
            {
                for (int j = 0; j < nums.size(); j++)
                {
                    if ((1 << i) & nums[j])
                    {
                        ones = ones ^ nums[j];
                    }
                }
                break;
            }
        }
        answer.push_back(ones);
        int other = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] ^ ones) == xorr)
            {
                answer.push_back(nums[i]);
                break;
            }
        }
        return answer;
    }
};