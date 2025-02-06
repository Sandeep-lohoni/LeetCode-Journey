// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and
// chooses the element in the next row that is either directly below or
// diagonally left / right.Specifically,
// the next element from position(row, col)
//  will be(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1 :

// Input : matrix = [ [ 2, 1, 3 ], [ 6, 5, 4 ], [ 7, 8, 9 ] ] Output : 13 Explanation : There are two falling paths with a minimum sum as shown.Example 2 :

// Input : matrix = [ [ -19, 57 ], [ -40, -5 ] ] Output : -59 Explanation : The falling path with a minimum sum is shown.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n, 1e9);
        vector<int> curr(n, 1e9);
        for (int j = 0; j < n; ++j)
        {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int up = matrix[i][j] + prev[j];
                int leftdiagonal = matrix[i][j];
                if (j - 1 >= 0)
                    leftdiagonal += prev[j - 1];
                else
                    leftdiagonal += 1e9;
                int rightdiagonal = matrix[i][j];
                if (j + 1 < n)
                    rightdiagonal += prev[j + 1];
                else
                    rightdiagonal += 1e9;
                curr[j] = min(up, min(leftdiagonal, rightdiagonal));
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};