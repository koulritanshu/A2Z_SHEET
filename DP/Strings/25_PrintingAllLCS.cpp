#include <bits/stdc++.h>
using namespace std;

// THIS IS A DIFFERENT PROBLEM
// WE NEED TO PRINT ALL THE LCSes

vector<string> all_longest_common_subsequences(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    // keeping track of visited in mp
    unordered_map<string, bool> mp;
    unordered_set<string> st;
    // first part of the pair(pair<int,int>) stores coordinates and second part(string) stores 
    // strings 
    queue<pair<pair<int, int>, string>> q;
    q.push({{0, 0}, ""});

    while (!q.empty())
    {
        auto indices = q.front().first;
        auto path = q.front().second;
        int x = indices.first;
        int y = indices.second;
        q.pop();

        if (x == n || y == m)
        {
            st.insert(path);
            continue;
        }

        string key = to_string(x) + "," + to_string(y) + "," + path;
        if (mp.count(key))
            continue;
        mp[key] = true;

        if (s[x] == t[y])
        {
            q.push({{x + 1, y + 1}, path + s[x]});
        }
        else
        {
            if (dp[x + 1][y] >= dp[x][y + 1])
            {
                q.push({{x + 1, y}, path});
            }
            if (dp[x][y + 1] >= dp[x + 1][y])
            {
                q.push({{x, y + 1}, path});
            }
        }
    }

    vector<string> ans(st.begin(), st.end());
    sort(ans.begin(), ans.end());

    return ans;
}