#include <bits/stdc++.h>
using namespace std;

class Brute
{
public:
    Brute()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        bool startPresent = false;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == beginWord)
            {
                startPresent = true;
                break;
            }
        }
        if (!startPresent)
        {
            wordList.push_back(beginWord);
        }
        vector<bool> vis(wordList.size(), 0);
        map<string, vector<string>> mp;
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                int cmp = 0;
                string a = wordList[i];
                string b = wordList[j];
                for (int x = 0; x < a.size(); x++)
                {
                    if (a[x] != b[x])
                        cmp++;
                }
                if (cmp == 1)
                {
                    mp[a].push_back(b);
                    mp[b].push_back(a);
                }
            }
        }
        map<string, int> indi;
        for (int i = 0; i < wordList.size(); i++)
        {
            indi[wordList[i]] = i;
        }
        queue<pair<string, int>> qp;
        qp.push({beginWord, 1});
        vis[indi[beginWord]] = 1;
        int ans = INT_MAX;
        if (beginWord == endWord)
            return 0;
        while (!qp.empty())
        {
            string curr = qp.front().first;
            int cnt = qp.front().second;
            qp.pop();
            if (curr == endWord)
            {
                ans = min(ans, cnt);
            }
            for (auto &i : mp[curr])
            {
                if (!vis[indi[i]])
                {
                    vis[indi[i]] = 1;
                    qp.push({i, cnt + 1});
                }
            }
        }
        if (ans == INT_MAX)
            ans = 0;
        return ans;
    }
};

class Optimal
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string, int>> qp;
        qp.push({beginWord, 1});
        while (!qp.empty())
        {
            string word = qp.front().first;
            int steps = qp.front().second;
            qp.pop();
            if (word == endWord)
            {
                return steps;
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        qp.push({word,steps+1});
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};