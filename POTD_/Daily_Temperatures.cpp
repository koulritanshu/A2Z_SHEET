#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/daily-temperatures/

// This problem is variation of Next Greater Element

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};

class Optimal
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; i--)
        {
            if (temperatures[i + 1] > temperatures[i])
            {
                ans[i] = 1;
            }
            else
            {
                int j = i + 1;
                while (j < temperatures.size() - 1 && temperatures[j] <= temperatures[i])
                {
                    if (ans[j] == 0)
                        break;
                    j = j + ans[j];
                }
                if (temperatures[j] > temperatures[i])
                {
                    ans[i] = j - i;
                }
                else
                {
                    ans[i] = 0;
                }
            }
        }
        return ans;
    }
};