#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atoi(string s)
    {
        bool neg = (s[0] == '-') ? true : false;
        if (!neg && (s[0] < '0' || s[0] > '9'))
            return -1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                return -1;
        }
        long long ans = 0;
        long long curr = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '-')
            {
                ans = ans * -1;
            }
            else
            {
                ans = ans + ((long long)(s[i] - '0')) * curr;
                curr = curr * (long long)10;
            }
        }
        return ans;
    }
};