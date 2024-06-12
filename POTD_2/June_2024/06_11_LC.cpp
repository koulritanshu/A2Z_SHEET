#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> mp;
        for (int i = 0; i < arr1.size(); i++)
            mp[arr1[i]]++;
        int ind = 0;
        int x = -1;
        for (int i = 0; i < arr1.size(); i++)
        {
            arr1[i] = arr2[ind];
            mp[arr2[ind]]--;
            if (mp[arr2[ind]] == 0)
            {
                mp.erase(arr2[ind]);
                ind++;
                if (ind == arr2.size())
                {
                    x = i;
                    break;
                }
            }
        }
        if (x == -1)
            return arr1;
        x++;
        for (auto &i : mp)
        {
            for (int j = 0; j < i.second; j++)
            {
                arr1[x] = i.first;
                x++;
            }
        }
        return arr1;
    }
};