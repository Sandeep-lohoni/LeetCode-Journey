// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> heights)
    {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> psum(n, vector<int>(m, 0));
        for (int j = 0; j < m; ++j)
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (matrix[i][j] == '1')
                    sum++;
                if (matrix[i][j] == '0')
                    sum = 0;
                psum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, largestRectangleArea(psum[i]));
        }
        return ans;
    }
};