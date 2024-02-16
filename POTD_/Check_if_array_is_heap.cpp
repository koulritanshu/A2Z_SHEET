#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n)
            {
                if (arr[i] < arr[left])
                    return false;
            }
            else
                return true;
            if (right < n)
            {
                if (arr[i] < arr[right])
                    return false;
            }
            else
                return true;
        }
        return true;
    }
};