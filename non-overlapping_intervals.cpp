// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool compare(vector<int> &m1, vector<int> &m2)
    {
        if (m1[1] < m2[1])
            return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int seen = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] >= seen)
            {
                seen = intervals[i][1];
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};