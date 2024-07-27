#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        if (arr1[n - 1] != arr2[n - 2])
            return n - 1;
        // 2 4 6 8   9   10  12
        // 2 4 6 8  10   12

        // 3 5 7 (8 x y)
        // 3 5 7 (x y)

        // 3 4 5 6 7 8
        // 3 5 6 7 8
        int st = 0, ed = n - 1;
        int ans = 0;
        while (st <= ed)
        {
            int mid = st + (ed - st) / 2;
            if (arr1[mid] != arr2[mid])
            {
                ans = mid;
                ed = mid - 1;
            }
            else
                st = mid + 1;
        }
        return ans;
    }
};