// Given a boolean 2D matrix grid of size n *m.You have to find the number of distinct islands where a group of connected 1s(horizontally or vertically) forms an island.Two islands are considered to be distinct if and only if one island is not equal to another(not rotated or reflected).

// Example 1 :

// Input : grid[][] = {{1, 1, 0, 0, 0},
//{1, 1, 0, 0, 0},
//{0, 0, 0, 1, 1},
//{0, 0, 0, 1, 1}} Output : 1 Explanation : grid[][] = {{1, 1, 0, 0, 0},
//{1, 1, 0, 0, 0},
//{0, 0, 0, 1, 1},
//{0, 0, 0, 1, 1}} Same colored islands are equal.We have 2 equal islands,
// so we
// have only 1 distinct island.

// Example 2 :

// Input : grid[][] = {{1, 1, 0, 1, 1},
//{1, 0, 0, 0, 0},
//{0, 0, 0, 0, 1},
//{1, 1, 0, 1, 1}} Output : 3 Explanation : grid[][] = {{1, 1, 0, 1, 1},
//{1, 0, 0, 0, 0},
//{0, 0, 0, 0, 1},
//{1, 1, 0, 1, 1}} Same colored islands are equal.We have 4 islands,
// but 2 of them
// are equal,
// So we have 3 distinct islands.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});
        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0, delrow, delcol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[4] = {-1, 0, 0, 1};
        int delcol[4] = {0, 1, -1, 0};
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j, delrow, delcol);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};