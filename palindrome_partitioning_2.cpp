// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    // memoization
    int f(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = 1e9;
        for (int j = i; j < n; ++j)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

public:
    int minCut(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return f(0, n, s, dp) - 1;
    }

    // tabulation
    int minCut(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            int mini = 1e9;
            for (int j = i; j < n; ++j)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};