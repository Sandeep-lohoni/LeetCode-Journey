// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights.Find the shortest weight path between the vertex 1 and the vertex n, if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path.If no path exists, then return a list containing a single element - 1.

// The input list of edges is as follows -
// {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.
// Note : The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the path, else - 1. In case the list contains only a single element(-1) it will simply output - 1.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (int i = 1; i <= m; ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        pq.push({0, 1});
        dist[1] = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int adjweight = it.second;

                if (dis + adjweight < dist[adjnode])
                {
                    dist[adjnode] = dis + adjweight;
                    pq.push({dist[adjnode], adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if (dist[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};