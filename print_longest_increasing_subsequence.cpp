// Given an integer n and an array of integers arr, return the Longest Increasing Subsequence which is Index-wise lexicographically smallest.
// Note - A subsequence S1 is Index-wise lexicographically smaller than a subsequence S2 if in the first position where S1 and S2 differ, subsequence S1 has an element that appears earlier in the array  arr than the corresponding element in S2.
// LIS  of a given sequence is defined as that longest possible subsequence all of whose elements are in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and the LIS is {10, 22, 33, 50, 60, 80}.

// Example 1:

// Input:
// n = 16
// arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
// Output:
// 0 4 6 9 13 15
// Explanation:
// longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.
// Example 2:

// Input:
// n = 1
// arr = [1]
// Output:
// 1

// solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);

        for (int ind = 0; ind < n; ++ind)
        {
            hash[ind] = ind;
            for (int prev_ind = 0; prev_ind < ind; ++prev_ind)
            {
                if (arr[ind] > arr[prev_ind] && 1 + dp[prev_ind] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev_ind];
                    hash[ind] = prev_ind;
                }
            }
        }

        int ans = 0;
        int lastindex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                lastindex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(arr[lastindex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};