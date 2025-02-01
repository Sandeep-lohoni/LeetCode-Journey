// Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.

// Examples :

//     Input : adj[][] = [ [ 2, 3 ], [0], [1], [4], [] ]

// Output : 3 Explanation : We can clearly see that there are 3 Strongly Connected Components in the Graph.

// Input : adj[][] = [ [1], [2], [0] ]

// Output : 1 Explanation : All of the nodes are connected to each other.So,
// there's only one SCC. Input : adj[][] = [ [1], [] ] Output : 2

// solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void finaldfs(int node, vector<int> &vis, vector<int> adjtrans[])
    {
        vis[node] = 1;
        for (auto it : adjtrans[node])
        {
            if (!vis[it])
            {
                finaldfs(it, vis, adjtrans);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &graph)
    {
        // code here
        int v = graph.size();
        vector<int> adj[v];
        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < graph[i].size(); ++j)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(v, 0);
        stack<int> st;
        for (int i = 0; i < v; ++i)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        vis = vector<int>(v, 0);
        vector<int> adjtrans[v];
        for (int i = 0; i < v; ++i)
        {
            for (auto it : adj[i])
            {
                adjtrans[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                finaldfs(node, vis, adjtrans);
            }
        }
        return scc;
    }
};