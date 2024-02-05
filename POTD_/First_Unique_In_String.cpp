#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = i;
            else
                mp[s[i]] = -1;
        }
        int ans = s.size();
        for (auto i : mp)
        {
            if (i.second != -1)
                ans = min(ans, i.second);
        }
        if (ans == s.size())
            ans = -1;
        return ans;
    }
};