// Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

// Example:

// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.
// Input: k = 1, arr[]= [10, 20, 10]
// Output: 20
// Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

// solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memo(int ind, vector<int> &dp, vector<int> &arr, int k)
    {
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int minsteps = INT_MAX;
        for (int i = 1; i <= k; ++i)
        {
            if (ind - i >= 0)
            {
                int jump = memo(ind - i, dp, arr, k) + abs(arr[ind] - arr[ind - i]);
                minsteps = min(minsteps, jump);
            }
        }
        return dp[ind] = minsteps;
    }
    int minimizeCost(int k, vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return memo(n - 1, dp, arr, k);
    }
};