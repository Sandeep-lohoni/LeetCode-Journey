// Given a weighted and directed graph of v vertices and edges, Find the shortest distance of all the vertex 's from the source vertex, src and return a list of integers where the ith integer denotes the distance of the ith node from the source node. If a vertices can' t be reach from the s then mark the distance as 10 ^ 8. Note : If the graph contains a negative cycle then return an array consisting of only - 1.

// Examples :

// Input : edges = [[ 0, 1, 9 ]],
// src = 0

// Output : [ 0, 9 ] Explanation : Shortest distance of all nodes from source is printed.Input : edges = [ [ 0, 1, 5 ], [ 1, 0, 3 ], [ 1, 2, -1 ], [ 2, 0, 1 ] ],
// src = 2

// Output : [ 1, 6, 0 ] Explanation : For nodes 2 to 0,
// we can follow the path : 2 - 0. This has a distance of 1. For nodes 2 to 1, we cam follow the path : 2 - 0 - 1, which has a distance of 1 + 5 = 6,

// solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; ++i)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // nth relaxation to check for negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};