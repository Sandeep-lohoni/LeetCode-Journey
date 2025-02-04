// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

// Example:

// Input: heights[] = [20, 30, 40, 20]
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20-30|  = 10
// Total Cost = 10 + 10 = 20
// Input: heights[] = [30, 20, 50, 10, 40]
// Output: 30
// Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
// jump from stair 0 to 2: cost = |50 - 30| = 20
// jump from stair 2 to 4: cost = |40-50|  = 10
// Total Cost = 20 + 10 = 30

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &heights)
    {
        // Code here
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            int jumpone = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int jumptwo = INT_MAX;
            if (i > 1)
                jumptwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            dp[i] = min(jumpone, jumptwo);
        }
        return dp[n - 1];
    }
};