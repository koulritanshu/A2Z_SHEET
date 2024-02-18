#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long ll;

bool isCyclicUtil(ll n, vector<vector<ll>>&graph,ll node, ll parent,vector<bool>&vis){
    vis[node] = true;
    for(auto i:graph[node]){
        if(!vis[i]){
            if(isCyclicUtil(n,graph,i,node,vis))
                return true;
        }
        else if(i != parent)
            return true;
    }
    return false;
}

bool isCycle(ll n, vector<vector<ll>>&graph){
    vector<bool>vis(n,false);
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            if(isCyclicUtil(n,graph,i,-1,vis)){
                return true;
            }
        }
    }
    return false;
}
