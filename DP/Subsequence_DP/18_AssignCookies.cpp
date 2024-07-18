#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ind1 = 0;
        int ind2 = 0;
        int ans = 0;
        while(ind1<g.size() && ind2<s.size()){
            if(g[ind1]<=s[ind2]){
                ans++;
                ind1++;
                ind2++;
            }
            else{
                ind2++;
            }
        }
        return ans;
    }
};