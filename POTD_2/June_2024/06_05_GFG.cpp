#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool func(int arr[], int n, int ele)
    {
        int st = 0, ed = n - 1;
        while (st <= ed)
        {
            int mid = st + (ed - st) / 2;
            if (arr[mid] == ele)
                return 1;
            else if (arr[mid] > ele)
                ed = mid - 1;
            else
                st = mid + 1;
        }
        return false;
    }
    int findSwapValues(int a[], int n, int b[], int m)
    {
        int suma = 0, sumb = 0;
        sort(a, a + n);
        sort(b, b + m);
        for (int i = 0; i < n; i++)
            suma += a[i];
        for (int i = 0; i < m; i++)
            sumb += b[i];
        if (suma == sumb)
            return 1;
        if (suma % 2 == 0 && sumb % 2)
            return -1;
        if (sumb % 2 == 0 && suma % 2)
            return -1;
        int diff = max(suma, sumb) - min(suma, sumb);
        diff /= 2;
        for (int i = 0; i < n; i++)
        {
            int ele;
            if (suma > sumb)
                ele = a[i] - diff;
            else
                ele = a[i] + diff;
            if (func(b, m, ele))
                return 1;
        }
        return -1;
    }
};