// Given a weighted, undirected and connected graph where you have given adjacency list adj.You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

// Note : The Graph doesn't contain any negative weight edge.

// Examples :

// Input : adj = [ [[ 1, 9 ]], [[ 0, 9 ]] ],
// src = 0 Output : [ 0, 9 ] Explanation :

// The source vertex is 0. Hence,
// the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9. Input : adj = [ [ [ 1, 1 ], [ 2, 6 ] ], [ [ 2, 3 ], [ 0, 1 ] ], [ [ 1, 3 ], [ 0, 6 ] ] ], src = 2 Output : [ 4, 3, 0 ] Explanation :

// For nodes 2 to 0,
// we can follow the path 2 - 1 - 0. This has a distance of 1 + 3 = 4, whereas the path 2 - 0 has a distance of 6. So, the Shortest path from 2 to 0 is 4. The shortest distance from 0 to 1 is 1 .

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        // Code here
        int v = adj.size();
        set<pair<int, int>> st;
        vector<int> dist(v, 1e9);
        dist[src] = 0;
        st.insert({0, src});
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for (auto it : adj[node])
            {
                int edgewt = it.second;
                int adjnode = it.first;
                if (dis + edgewt < dist[adjnode])
                {
                    if (dist[adjnode] != 1e9)
                    {
                        st.erase({dist[adjnode], adjnode});
                    }
                    dist[adjnode] = dis + edgewt;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};
