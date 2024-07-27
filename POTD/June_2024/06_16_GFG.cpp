#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getPrimes(int n)
    {
        vector<int> prime(n + 1, true);
        prime[0] = prime[1] = false;
        vector<int> ans(2, -1);
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n / 2 + 1; i++)
        {
            if (prime[i] && prime[n - i])
            {
                ans[0] = i;
                ans[1] = n - i;
                break;
            }
        }
        return ans;
    }
};