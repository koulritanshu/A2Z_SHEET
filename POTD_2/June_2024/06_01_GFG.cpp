#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(string s)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
        }
        int ans = 0;
        for (char x = 'a'; x <= 'z'; x++)
        {
            int frequency = v[x - 'a'];
            int position = (int)(x - 'a') + 1;
            if ((position % 2) == (frequency % 2) && frequency)
            {
                ans++;
            }
        }
        if (ans % 2 == 0)
            return "EVEN";
        return "ODD";
    }
};