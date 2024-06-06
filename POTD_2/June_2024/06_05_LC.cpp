#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> v(26, INT_MAX);
        for (int i = 0; i < words.size(); i++)
        {
            vector<int> v1(26, 0);
            for (int j = 0; j < words[i].size(); j++)
            {
                v1[words[i][j] - 'a']++;
            }
            for (int x = 0; x < 26; x++)
            {
                v[x] = min(v[x], v1[x]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            string x = "";
            x += (i + 'a');
            while (v[i] > 0)
            {
                ans.push_back(x);
                v[i]--;
            }
        }
        return ans;
    }
};