// There are n servers numbered from 0 to n - 1 connected by undirected server - to - server connections forming a network where connections[i] = [ ai, bi ] represents a connection between servers ai and bi.Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that,
// if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Example 1 :

// Input : n = 4,
// connections = [ [ 0, 1 ], [ 1, 2 ], [ 2, 0 ], [ 1, 3 ] ] Output : [[ 1, 3 ]] Explanation : [[ 3, 1 ]] is also accepted.Example 2 :

// Input : n = 2,
// connections = [[ 0, 1 ]] Output : [[ 0, 1 ]]

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int timer = 1;

private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, tin, low, adj, bridges);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    bridges.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, tin, low, adj, bridges);
        return bridges;
    }
};