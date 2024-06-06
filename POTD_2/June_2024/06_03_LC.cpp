#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int indexs = 0;
        int indext = 0;
        while (indexs < s.size() && indext < t.size())
        {
            if (s[indexs] == t[indext])
            {
                indext++;
            }
            indexs++;
        }
        return t.size() - indext;
    }
};