// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32 -
// bit signed integer.

// Example 1 :

//     Input : s = "rabbbit",
//             t = "rabbit" Output : 3 Explanation : As shown below, there are 3 ways you can generate "rabbit" from s.rabbbit rabbbit rabbbit Example 2 :

//     Input : s = "babgbag",
//             t = "bag" Output : 5 Explanation : As shown below, there are 5 ways you can generate "bag" from s.babgbag babgbag babgbag babgbag babgbag

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int mod = 1e9 + 7;

public:
    // use dp n*m size;
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= m; ++j)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
                }
                else
                    dp[i][j] = (dp[i - 1][j]) % mod;
            }
        }
        return dp[n][m];
    }
    // use only m size;
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<int> prev(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j >= 1; --j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    prev[j] = (prev[j] + prev[j - 1]) % mod;
                }
            }
        }
        return prev[m];
    }
};