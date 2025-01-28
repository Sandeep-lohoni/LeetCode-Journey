// You are given two integers 'n' and 'm', the dimensions of a grid.The coordinates are from(0, 0) to(n - 1, m - 1).

// The grid can only have values 0 and 1.

// The value is 0 if there is water and 1 if there is land.

// An island is a group of ‘1’s such that every ‘1’ has at least another ‘1’ sharing a common edge.

// You are given an array 'queries' of size 'q'.

// Each element in 'queries' contains two integers 'x' and 'y',
// referring to the coordinates in the grid.

// Initially,
// the grid is filled with 0, which means only water and no land.

// At each query,
// the value of 'grid' at(x, y) becomes 1, which means it becomes land.

// Find out,
// after each query, the number of islands in the grid.

// Example : Input : 'n' = 3,
//'m' = 4 'queries' = [ [ 1, 1 ], [ 1, 2 ], [ 2, 3 ] ]

// Output : [ 1, 1, 2 ]

// Explanation :

// Initially,
// the grid was : 0 0 0 0 0 0 0 0 0 0 0 0

// After query(1, 1) : 0 0 0 0 0 1 0 0 0 0 0 0 There is one island having land(1, 1)

// After query(1, 2) : 0 0 0 0 0 1 1 0 0 0 0 0 Since(1, 1) and
//(1, 2) share a common edge,
// they form one island.So there is one island having lands(1, 1) and (1, 2).

// After query(2, 3) : 0 0 0 0 0 1 1 0 0 0 0 1 Now there are two islands,
// one having lands(1, 1) and (1, 2), and another having land(2, 3).

// So the number of islands after each query is[1, 1, 2]

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
    vector<int> numberOfIslandII(int n, int m, vector<vector<int>> &queries, int q)
    {
        // Write your code here.
        DisjointSet ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;
        for (auto it : queries)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[4] = {-1, 0, 0, 1};
            int dc[4] = {0, -1, 1, 0};
            for (int i = 0; i < 4; ++i)
            {
                int adjrow = row + dr[i];
                int adjcol = col + dc[i];
                if (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m)
                {
                    if (vis[adjrow][adjcol] == 1)
                    {
                        int nodenumber = row * m + col;
                        int adjnumber = adjrow * m + adjcol;
                        if (ds.findUParent(nodenumber) != ds.findUParent(adjnumber))
                        {
                            cnt--;
                            ds.unionBySize(nodenumber, adjnumber);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};