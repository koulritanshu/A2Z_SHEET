#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] > heights[i - 1])
            {
                if (ladders > 0)
                {
                    ladders--;
                    pq.push(heights[i] - heights[i - 1]);
                }
                else
                {
                    int curr = heights[i] - heights[i - 1];
                    if (!pq.empty() && curr > pq.top())
                    {
                        int t = pq.top();
                        pq.pop();
                        pq.push(curr);
                        if (bricks < t)
                            return i - 1;
                        bricks -= t;
                    }
                    else
                    {
                        if (bricks < curr)
                        {
                            return i - 1;
                        }
                        else
                        {
                            bricks -= curr;
                        }
                    }
                }
            }
        }
        return (int)heights.size() - 1;
    }
};