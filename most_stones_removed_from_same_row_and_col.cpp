// On a 2D plane, we place n stones at some integer coordinate points.Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or
// the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [ xi, yi ] represents the location of the ith stone,
// return the largest possible number of stones that can be removed.

// Example 1 :

// Input : stones = [ [ 0, 0 ], [ 0, 1 ], [ 1, 0 ], [ 1, 2 ], [ 2, 1 ], [ 2, 2 ] ] Output : 5 Explanation : One way to remove 5 stones is as follows : 1. Remove stone[2, 2] because it shares the same row as[2, 1].2. Remove stone[2, 1] because it shares the same column as[0, 1].3. Remove stone[1, 2] because it shares the same row as[1, 0].4. Remove stone[1, 0] because it shares the same column as[0, 0].5. Remove stone[0, 1] because it shares the same row as[0, 0].Stone[0, 0] cannot be removed since it does not share a row / column with another stone still on the plane.Example 2 :

// Input : stones = [ [ 0, 0 ], [ 0, 2 ], [ 1, 1 ], [ 2, 0 ], [ 2, 2 ] ] Output : 3 Explanation : One way to make 3 moves is as follows : 1. Remove stone[2, 2] because it shares the same row as[2, 0].2. Remove stone[2, 0] because it shares the same column as[0, 0].3. Remove stone[0, 2] because it shares the same row as[0, 0].Stones[0, 0] and [ 1, 1 ] cannot be removed since they do not share a row / column with another stone still on the plane.Example 3 :

// Input : stones = [[ 0, 0 ]] Output : 0 Explanation : [ 0, 0 ] is the only stone on the plane,
//so you cannot remove it.

// solution

#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{

public:
    vector<int> size, parent;
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for (auto it : stones)
        {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int, int> stonenodes;
        for (auto it : stones)
        {
            int noderow = it[0];
            int nodecol = maxrow + 1 + it[1];
            ds.unionBySize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int components = 0;
        for (auto it : stonenodes)
        {
            int node = it.first;
            if (ds.findUParent(node) == node)
                components++;
        }
        return n - components;
    }
};