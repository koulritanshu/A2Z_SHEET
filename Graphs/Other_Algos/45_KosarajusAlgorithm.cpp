#include <bits/stdc++.h>
using namespace std;

// 1. Kosaraju's Algorithm is used to find strongly connected components.
// 2. Strongly Connected Components are only valid for Directed Graphs.
// 3. In a strongly connected component, all pair of vertices are reachable from each other.

// Kosaraju Algo

// 1. Sort all edges according to starting time.
// 2. Reverse all the edges.
// 3. Start a dfs traversal.

class Kosaraju
{
    // Time Complexity - 3 DFS Traversals so O(3*(V+E))
    // Space Complexity - 1 stack (V) + 1 vector_vis(V) + adj2(V+E) = O(V + V + V + E) 
public:
    void dfs(int curr, vector<vector<int>>&adj, vector<bool>&vis,stack<int> &st){
        vis[curr] = true;
        for(auto &i:adj[curr]){
            if(!vis[i]){
                vis[i] = true;
                dfs(i,adj,vis,st);   
            }
        }
        st.push(curr);
    }
    void dfs(int curr, vector<bool>&vis, vector<vector<int>>&adj){
        vis[curr]=true;
        for(auto &i:adj[curr]){
            if(!vis[i]){
                vis[i] = true;
                dfs(i,vis,adj);
            }
        }
    }
	int kosaraju(int V, vector<vector<int>>& adj)
    {
        // sort nodes according to starting time
        vector<bool> vis(V,false); 
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        // Now stack st contains the sorted order of nodes
        vector<vector<int>> adj2(V,vector<int>());
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                int b = adj[i][j];
                int a = i;
                adj2[b].push_back(a);
            }
        }
        // now perform dfs and count the number of dfs traversals
        vis = vector<bool>(V,false);
        int cnt = 0;
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(!vis[i]){
                dfs(i,vis,adj2);
                cnt++;
            }
        }
        return cnt;
    }
};