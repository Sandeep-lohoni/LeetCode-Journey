// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int start, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[start] = 1;
        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(start);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Your code here
        int v = adj.size();
        vector<int> vis(v, 0);
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < v; ++i)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};