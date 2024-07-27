#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        string ans = "";
        char add = '1';
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char curr = s[i];
            if (curr == '1' && add == '1')
            {
                ans += '0';
                add = '1';
            }
            else if (curr == '1' || add == '1')
            {
                ans += '1';
                add = '0';
            }
            else
            {
                ans += '0';
                add = '0';
            }
        }
        if (add == '1')
        {
            ans += '1';
            add = '0';
        }
        while (ans[ans.size() - 1] == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};