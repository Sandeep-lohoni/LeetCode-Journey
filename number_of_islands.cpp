// Given an m x n 2D binary grid grid which represents a map of '1' s(land) and '0' s(water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally
// or vertically.You may assume all four edges of the grid are all surrounded by water.
// Example 1 :
//     Input : grid = [
//     [ "1", "1", "1", "1", "0" ],
//     [ "1", "1", "0", "1", "0" ],
//     [ "1", "1", "0", "0", "0" ],
//     [ "0", "0", "0", "0", "0" ]
// ] 
// Output : 1 
// Example 2 :
//     Input : grid = [
//         [ "1", "1", "0", "0", "0" ],
//         [ "1", "1", "0", "0", "0" ],
//         [ "0", "0", "1", "0", "0" ],
//         [ "0", "0", "0", "1", "1" ]
//     ] 
//     Output : 3

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < m; ++col)
            {
                if (vis[row][col] == 0 && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};