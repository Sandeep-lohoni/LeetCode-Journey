// Given a triangle array, return the minimum path sum from top to bottom.

// For each step,
// you may move to an adjacent number of the row below.More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1 :

// Input : triangle = [ [2], [ 3, 4 ], [ 6, 5, 7 ], [ 4, 1, 8, 3 ] ] Output : 11 Explanation : The triangle looks like : 2 3 4 6 5 7 4 1 8 3 The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11(underlined above).Example 2 :

// Input : triangle = [[-10]] Output : -10

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n, 0);
        for (int j = 0; j < n; ++j)
        {
            front[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};