// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded :
// Connect : A cell is connected to adjacent cells horizontally or vertically.Region : To form a region connect every 'O' cell.Surround : The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.To capture a surrounded region,replace all 'O' s with 'X' s in - place within the original board.You do not need to return anything.
// Example 1 :
//     Input : board = [ [ "X", "X", "X", "X" ], [ "X", "O", "O", "X" ], [ "X", "X", "O", "X" ], [ "X", "O", "X", "X" ] ]
//     Output : [ [ "X", "X", "X", "X" ], [ "X", "X", "X", "X" ], [ "X", "X", "X", "X" ], [ "X", "O", "X", "X" ] ]
// Explanation :
//     In the above diagram,
// the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
// Example 2 :
//     Input : board = [["X"]]
// Output : [["X"]]

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &board, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < board.size() && ncol >= 0 &&
                ncol < board[0].size() && board[nrow][ncol] == 'O' &&
                !vis[nrow][ncol])
            {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int delrow[4] = {0, -1, 1, 0};
        int delcol[4] = {-1, 0, 0, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; ++i)
        {
            if (!vis[0][i] && board[0][i] == 'O')
            {
                dfs(0, i, vis, board, delrow, delcol);
            }
            if (!vis[n - 1][i] && board[n - 1][i] == 'O')
            {
                dfs(n - 1, i, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};