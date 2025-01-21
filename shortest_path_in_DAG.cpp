// Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

// Examples :

// Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
// Output: [0, 2, 1, -1]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

// solution

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void dfs(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                dfs(v, vis, adj, st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};