// Given an undirected graph with V vertices.We say two vertices u and v belong to a single province if there is a path from u to v or v to u.Your task is to find the number of provinces.

//                                                                                                                                     Note : A province is a group of directly or
//     indirectly connected cities and no other cities outside of the group.

// solution

#include <bits/stdc++.h>
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
    int numProvinces(vector<vector<int>> grid, int V)
    {
        DisjointSet ds(V);
        int cnt = 0;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        for (int i = 0; i < V; ++i)
        {
            if (ds.findUParent(i) == i)
                cnt++;
        }
        return cnt;
    }
};