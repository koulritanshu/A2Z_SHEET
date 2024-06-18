#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < profit.size(); i++)
        {
            vp.push_back({difficulty[i], profit[i]});
        }
        sort(vp.begin(), vp.end());
        vector<int> maxi(vp.size(), 0);
        maxi[0] = vp[0].second;
        for (int i = 1; i < vp.size(); i++)
        {
            maxi[i] = max(maxi[i - 1], vp[i].second);
        }
        int ans = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            int curr = worker[i];
            int st = 0, ed = vp.size() - 1;
            int anss = 0;
            while (st <= ed)
            {
                int mid = st + (ed - st) / 2;
                if (vp[mid].first <= curr)
                {
                    anss = maxi[mid];
                    st = mid + 1;
                }
                else
                {
                    ed = mid - 1;
                }
            }
            ans += anss;
        }
        return ans;
    }
};