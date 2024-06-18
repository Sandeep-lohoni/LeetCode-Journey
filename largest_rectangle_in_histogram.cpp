// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int leftsmall[n], rightsmall[n];
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;
            st.push(i);
        }
        int maxarea = 0;
        for (int i = 0; i < n; ++i)
        {
            maxarea = max(maxarea, (rightsmall[i] - leftsmall[i] + 1) * heights[i]);
        }
        return maxarea;
    }
};