#include <bits/stdc++.h>
using namespace std;

class BRUTE
{
public:
    bool check(string &a, string &b)
    {
        int cmp = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                cmp++;
        }
        return (cmp == 1);
    }
    void func(vector<vector<string>> &reachEnd, unordered_map<string, vector<string>> &v, string &curr, string &endWord, unordered_map<string, bool> &vis, vector<string> &vec)
    {
        if (curr == endWord)
        {
            reachEnd.push_back(vec);
            reachEnd[reachEnd.size() - 1].push_back(endWord);
            return;
        }
        // cout << "curr = " << curr << endl;
        vec.push_back(curr);
        vis[curr] = true;
        for (auto &i : v[curr])
        {
            if (vis[i] != true)
            {
                func(reachEnd, v, i, endWord, vis, vec);
            }
        }
        vis[curr] = false;
        vec.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> vis;
        vector<string> vec;
        wordList.push_back(beginWord);
        // for(int i=0;i<reachEnd.size();i++){
        //     for(int j=0;j<reachEnd[i].size();j++){
        //         cout << reachEnd[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < wordList.size(); i++)
        {
            for (int j = i + 1; j < wordList.size(); j++)
            {
                string a = wordList[i];
                string b = wordList[j];
                if (check(a, b))
                {
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }
        // for(auto i:graph){
        //     cout << i.first << " ";
        //     for(auto j:i.second){
        //         cout << j << " ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<string>> reachEnd;
        func(reachEnd, graph, beginWord, endWord, vis, vec);
        int min_length = INT_MAX;
        for (int i = 0; i < reachEnd.size(); i++)
        {
            min_length = min(min_length, (int)reachEnd[i].size());
        }
        vector<vector<string>> ans;
        for (int i = 0; i < reachEnd.size(); i++)
        {
            if (reachEnd[i].size() == min_length)
            {
                ans.push_back(reachEnd[i]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            if (v.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = v.back();
            if (word == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(v);
                }
                else if (ans[0].size() == v.size())
                {
                    ans.push_back(v);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char x = 'a'; x <= 'z'; x++)
                {
                    word[i] = x;
                    if (st.count(word) > 0)
                    {
                        v.push_back(word);
                        q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};