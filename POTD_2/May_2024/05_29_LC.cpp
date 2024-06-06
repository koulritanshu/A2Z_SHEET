#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countZeroes(string &s)
    {
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                cnt++;
                s.pop_back();
            }
            else
                break;
        }
        return cnt;
    }
    int Addi(string &s)
    {
        // find zero from back and maintain count of ones
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                cnt++;
                s.pop_back();
            }
            else
            {
                s[i] = '1';
                break;
            }
        }
        return cnt;
    }
    int numSteps(string s)
    {
        int steps = 0;
        int cnt = 0;
        while (s.size() > 1)
        {
            steps += countZeroes(s);
            // 101010100000001
            if (s.size() <= 1)
                break;
            steps += Addi(s) + 1;
            // cout << s << endl;
            cnt++;
        }
        return steps;
    }
};