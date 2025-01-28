// You are given an n x n binary matrix grid.You are allowed to change at most one 0 to be 1.

//     Return the size of the largest island in grid after applying this operation.

//     An island is a 4 -
//     directionally connected group of 1s.

//     Example 1 :

//     Input : grid = [ [ 1, 0 ], [ 0, 1 ] ] Output : 3 Explanation : Change one 0 to 1 and connect two 1s,
//             then we get an island with area = 3. Example 2 :

//     Input : grid = [ [ 1, 1 ], [ 1, 0 ] ] Output : 4 Explanation : Change the 0 to 1 and make the island bigger,
//             only one island with area = 4. Example 3 :

//     Input : grid = [ [ 1, 1 ], [ 1, 1 ] ] Output : 4 Explanation : Can't change any 0 to 1, only one island with area = 4.

// solution

#include <bits/stdc++.h>
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
private:
    bool isvalid(int x, int y, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (grid[row][col] == 0)
                    continue;
                int di[4] = {-1, 0, 0, 1};
                int dj[4] = {0, -1, 1, 0};
                for (int ind = 0; ind < 4; ++ind)
                {
                    int nrow = row + di[ind];
                    int ncol = col + dj[ind];
                    if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                    {
                        int node = row * n + col;
                        int adjnode = nrow * n + ncol;
                        ds.unionBySize(node, adjnode);
                    }
                }
            }
        }
        int maxi = 0;
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (grid[row][col] == 1)
                    continue;
                int di[4] = {-1, 0, 0, 1};
                int dj[4] = {0, -1, 1, 0};
                set<int> components;
                for (int ind = 0; ind < 4; ++ind)
                {
                    int nrow = row + di[ind];
                    int ncol = col + dj[ind];
                    if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                    {
                        int adjnode = nrow * n + ncol;
                        components.insert(ds.findUParent(adjnode));
                    }
                }
                int sizetotal = 0;
                for (auto it : components)
                {
                    sizetotal += ds.size[it];
                }
                maxi = max(maxi, sizetotal + 1);
            }
        }
        for (int cell = 0; cell < n * n; ++cell)
        {
            maxi = max(maxi, ds.size[ds.findUParent(cell)]);
        }
        return maxi;
    }
};