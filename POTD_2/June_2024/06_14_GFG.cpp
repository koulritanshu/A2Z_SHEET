#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string armstrongNumber(int n)
    {
        int sum = 0;
        int temp = n;
        while (n)
        {
            sum += ((n % 10) * (n % 10) * (n % 10));
            n = n / 10;
        }
        if (sum == temp)
            return "Yes";
        return "No";
    }
};