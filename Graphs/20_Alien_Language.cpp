#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(N * |S| + K)
// Space Complexity = O(K)

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        vector<int> indegree(K, 0);
        for (int i = 0; i < N - 1; i++)
        {
            string curr = dict[i];
            string next = dict[i + 1];
            for (int j = 0; j < min(curr.size(), next.size()); j++)
            {
                if (curr[j] != next[j])
                {
                    int ind1 = curr[j] - 'a';
                    int ind2 = next[j] - 'a';
                    adj[ind1].push_back(ind2);
                    indegree[ind2]++;
                    break;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        string ans = "";
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            char curr = 'a' + fr;
            ans += curr;
            for (auto &i : adj[fr])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans;
    }
};