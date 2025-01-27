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

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += weight;
            for (auto it : adj[node])
            {
                int adjnode = it[0];
                int edgeweight = it[1];
                if (!vis[adjnode])
                {
                    pq.push({edgeweight, adjnode});
                }
            }
        }
        return sum;
    }
};