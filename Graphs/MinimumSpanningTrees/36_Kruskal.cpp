#include <bits/stdc++.h>
#include "34_Disjoint_Set_Rank.cpp"
using namespace std;

class Solution
{   
public:
	int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> vp;
        for(int i=0;i<V;i++){
            for(auto &j:adj[i]){
                vp.push_back({j[1],{i,j[0]}});
            }
        }
        sort(vp.begin(),vp.end());
        int taken = 0;
        int costt = 0;
        DisjointRank ds(V+1);
        for(int i=0;i<vp.size();i++){
            int cost = vp[i].first;
            int st_no = vp[i].second.first;
            int ed_no = vp[i].second.second;
            if(ds.connectedComponents(st_no,ed_no)){
                continue;
            }
            else{
                costt += cost;
                ds.unionByRank(st_no, ed_no);
            }
            taken++;
            if(taken==V-1) return costt;
        }
        return costt;
    }
};