// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree(MST)
// of the graph.The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

// Input : 3 3 0 1 5 1 2 3 0 2 1

// Output : 4 Explanation :

// The Spanning Tree resulting in a weight of 4 is shown above.Input : 2 1 0 1 5

// Output : 5

// Explanation : Only one Spanning Tree is possible which has a weight of 5.

// solution

#include <bits/stdc++.h>
using namespace std;

class Disjointset
{
    vector<int> size, parent;

public:
    Disjointset(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }
    int findUparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionbysize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; ++i)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int w = it[1];
                edges.push_back({w, {u, v}});
            }
        }
        Disjointset ds(V);
        sort(edges.begin(), edges.end());
        int sum = 0;
        for (auto it : edges)
        {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUparent(u) != ds.findUparent(v))
            {
                sum += w;
                ds.unionbysize(u, v);
            }
        }
        return sum;
    }
};