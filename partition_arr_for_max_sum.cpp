// Given an integer array arr, partition the array into(contiguous)
// subarrays of length at most k.After partitioning, each subarray has their values changed to become the maximum value of that subarray.

//                                                       Return the largest sum of the given array after partitioning.Test cases are generated so that the answer fits in a 32 -
//                                                       bit integer.

//                                                       Example 1 :

//     Input : arr = [ 1, 15, 7, 9, 2, 5, 10 ],
//             k = 3 Output : 84 Explanation : arr becomes[15, 15, 15, 9, 10, 10, 10] Example 2 :

//     Input : arr = [ 1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3 ],
//             k = 4 Output : 83 Example 3 :

//     Input : arr = [1],
//             k = 1 Output : 1

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // memoization
private:
    int f(int i, int n, int k, vector<int> &arr, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int len = 0;
        int maxelem = -1e9;
        int maxans = -1e9;
        for (int j = i; j < min(n, i + k); ++j)
        {
            len++;
            maxelem = max(maxelem, arr[j]);
            int sum = maxelem * len + f(j + 1, n, k, arr, dp);
            maxans = max(maxans, sum);
        }
        return dp[i] = maxans;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, k, arr, dp);
    }

    // tabulation
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            int len = 0;
            int maxelem = -1e9;
            int maxans = -1e9;
            for (int j = i; j < min(n, i + k); ++j)
            {
                len++;
                maxelem = max(maxelem, arr[j]);
                int sum = maxelem * len + dp[j + 1];
                maxans = max(maxans, sum);
            }
            dp[i] = maxans;
        }
        return dp[0];
        ;
    }
};