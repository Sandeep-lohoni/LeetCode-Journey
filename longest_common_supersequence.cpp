// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from
// t(possibly 0) results in the string s.

// Example 1 :

// Input : str1 = "abac",
// str2 = "cab" Output : "cabac" Explanation : str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".The answer provided is the shortest such string that satisfies these properties.Example 2 :

//     Input : str1 = "aaaaaaaa",
//             str2 = "aaaaaaaa" Output : "aaaaaaaa"

// solution

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1][ind2 - 1], dp[ind1 - 1][ind2]);
            }
        }

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
        while (i > 0)
        {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += s2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};