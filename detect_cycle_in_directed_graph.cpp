// Given a Directed Graph with V vertices(Numbered from 0 to V - 1) and E edges, check whether it contains any cycle or not .The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i.Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int start, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
    {
        vis[start] = 1;
        pathVis[start] = 1;
        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, pathVis, adj) == true)
                    return true;
            }
            else if (pathVis[it] == 1)
                return true;
        }
        pathVis[start] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, pathVis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};