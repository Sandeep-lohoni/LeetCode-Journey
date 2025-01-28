// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ ai, bi ] represents a connection between computers ai and bi.Any computer can reach any other computer directly or indirectly through the network.

//You are given an initial computer network connections.You can extract certain cables between two directly connected computers,
//                                                                                                                 and place them between any pair of disconnected computers to make them directly connected.

//Return the minimum number of times you need to do this in order to make all the computers connected.If it is not possible,
//                                                                                                                 return -1.

//Example 1 :

//Input : n = 4,
//connections = [ [ 0, 1 ], [ 0, 2 ], [ 1, 2 ] ] Output : 1 Explanation : Remove cable between computer 1 and 2 and place between computers 1 and 3. Example 2 :

//Input : n = 6,
//connections = [ [ 0, 1 ], [ 0, 2 ], [ 0, 3 ], [ 1, 2 ], [ 1, 3 ] ] Output : 2 Example 3 :

//Input : n = 6,
//connections = [ [ 0, 1 ], [ 0, 2 ], [ 0, 3 ], [ 1, 2 ] ] Output : -1 Explanation : There are not enough cables.

// solution

#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int extraedges = 0;
        int components = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUParent(u) == ds.findUParent(v))
                extraedges++;
            else
                ds.unionBySize(u, v);
        }
        for (int i = 0; i < n; ++i)
        {
            if (ds.findUParent(i) == i)
                components++;
        }
        int ans = components - 1;
        if (extraedges >= ans)
            return ans;
        return -1;
    }
};