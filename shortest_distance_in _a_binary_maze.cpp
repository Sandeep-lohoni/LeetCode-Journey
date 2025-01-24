// Given a 2D binary matrix A(0 - based index) of dimensions NxM.Find the minimum number of steps required to reach from(0, 0) to(X, Y).Note : You can only move left, right, up and down, and only through cells that contain 1.

// Example 1 :

// Input : N = 3,
// M = 4 A = [
// [ 1, 0, 0, 0 ],
// [ 1, 1, 0, 1 ],
// [ 0, 1, 1, 1 ] ]
// X = 2,
// Y = 3 Output : 5 Explanation : The shortest path is as follows : (0, 0)->(1, 0)->(1, 1)->(2, 1)->(2, 2)->(2, 3).Example 2 :

// Input : N = 3,
// M = 4 A = [
// [ 1, 1, 1, 1 ],
// [ 0, 0, 0, 1 ],
// [ 0, 0, 0, 1 ] ]
// X = 0,Y = 3 Output : 3 Explanation : The shortest path is as follows : (0, 0)->(0, 1)->(0, 2)->(0, 3).
// Your Task : You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int x, int y)
    {
        // code here
        if (grid[0][0] == 0)
            return -1;
        if (x == 0 && y == 0)
            return 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, 1, -1};
        while (!q.empty())
        {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && dist[nrow][ncol] > d + 1)
                {
                    dist[nrow][ncol] = d + 1;
                    if (nrow == x && ncol == y)
                        return d + 1;
                    q.push({d + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};