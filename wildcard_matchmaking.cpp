// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // use n*m size
    bool isMatch(string s2, string s1)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; ++j)
            dp[0][j] = false;
        for (int i = 1; i <= n; ++i)
        {
            bool flag = true;
            for (int k = 1; k <= i; ++k)
            {
                if (s1[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    if (s1[i - 1] == '*')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }

    // use m size
    bool isMatch(string s2, string s1)
    {
        int n = s1.size();
        int m = s2.size();
        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            bool flag = true;
            for (int k = 1; k <= i; ++k)
            {
                if (s1[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    curr[j] = prev[j - 1];
                else
                {
                    if (s1[i - 1] == '*')
                    {
                        curr[j] = prev[j] || curr[j - 1];
                    }
                    else
                        curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};