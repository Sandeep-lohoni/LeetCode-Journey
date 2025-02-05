// Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

//Note : You can only move either down or right at any point in time.

//Example 1 :

//Input : grid = [ [ 1, 3, 1 ], [ 1, 5, 1 ], [ 4, 2, 1 ] ] Output : 7 Explanation : Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.Example 2 :

//Input : grid = [ [ 1, 2, 3 ], [ 4, 5, 6 ] ] Output : 12

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; ++i)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else
                {
                    int down = grid[i][j];
                    if (i > 0)
                        down += prev[j];
                    else
                        down += 1e9;
                    int right = grid[i][j];
                    if (j > 0)
                        right += curr[j - 1];
                    else
                        right += 1e9;
                    curr[j] = min(down, right);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};