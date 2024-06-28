#include <bits/stdc++.h>
using namespace std;

// Logic: Assign scores greedily (select max degree and assign max_value to max degree and so on).

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n,0);
        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];
            degree[a]++;
            degree[b]++;
        }
        long long ans = 0;
        long long curr_val = 1;
        sort(degree.begin(),degree.end());
        for(int i=0;i<degree.size();i++){
            ans += (curr_val*degree[i]);
            curr_val++;
        }
        return ans;
    }
};

class EasyToUnderstand {
public:
    EasyToUnderstand(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    static bool cmp(pair<long long,long long>&a, pair<long long,long long>&b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> degree(n);
        for(int i=0;i<n;i++){
            degree[i].first = i;
            degree[i].second = 0;
        }
        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];
            degree[a].second++;
            degree[b].second++;
        }
        sort(degree.begin(),degree.end(),cmp);
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            mp[degree[i].first] = n-i;
        }
        long long ans = 0;
        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];
            ans += (mp[a]+mp[b]);
        }
        return ans;
    }
};

// each value assigned to a particular node will occur degree times 
// so instead of using a map, multiply degree by value assigned