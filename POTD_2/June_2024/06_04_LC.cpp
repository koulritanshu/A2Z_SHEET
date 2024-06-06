#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        int cnt = 0;
        bool odd = false;
        for (auto &i : mp)
        {
            if (i.second % 2)
            {
                cnt += i.second - 1;
                odd = true;
            }
            else
                cnt += i.second;
        }
        if (odd)
            cnt++;
        return cnt;
    }
};