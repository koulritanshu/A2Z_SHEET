#include <bits/stdc++.h>
using namespace std;

class DFS {
public:
    // -1 not terminal
    // 1 terminal
    // 0 not visited
    // 2 visited
    bool dfs(vector<vector<int>>&graph, int curr, vector<int>&vis){
        vis[curr] = 2;
        bool ans = true;
        for(auto &i:graph[curr]){
            if(vis[i]==2){
                vis[curr]=-1;
                return false;
            }
            else if(vis[i]==-1){
                vis[curr] = -1;
                return false;
            }
            else if(vis[i]==0){
                ans = (ans && dfs(graph,i,vis));
            }
        }
        if(ans){
            vis[curr] = 1;
            return true;
        }
        else{
            vis[curr] = -1;
            return false;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){
                vis[i] = 1;
            }
        }
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                if(dfs(graph,i,vis)){
                    ans.push_back(i);
                }
            }
            else if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class TopologicalSort {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q; 
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            ans.push_back(fr);
            for(auto &it:adj[fr]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};