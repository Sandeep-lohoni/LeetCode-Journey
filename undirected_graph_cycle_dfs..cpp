// Given an undirected graph with V vertices labelled from 0 to V - 1 and E edges, check whether the graph contains any cycle or not .The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.
// NOTE : The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].
// Examples : Input : adj = [ [1], [ 0, 2, 4 ], [ 1, 3 ], [ 2, 4 ], [ 1, 3 ] ] Output : 1 Explanation : 1->2->3->4->1 is a cycle.
// Input : adj = [ [], [2], [ 1, 3 ], [2] ] Output : 0 Explanation :No cycle in the graph.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto current : adj[node])
        {
            if (!vis[current])
            {
                if (dfs(current, node, adj, vis))
                    return true;
            }
            else if (current != parent)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int v = adj.size();
        vector<int> vis(v, 0);
        for (int i = 0; i < v; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};