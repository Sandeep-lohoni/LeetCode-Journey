// You are given two strings ‘s1’ and ‘s2’.

//     Return the longest common subsequence of these strings.

//     If there’s no such string,
//     return an empty string.If there are multiple possible answers, return any such string.

// Note : Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’.A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or
// more(possibly zero) characters from ‘s1’.

// Example : Input : ‘s1’ = “abcab”, ‘s2’ = “cbab”

//                                                                                                                     Output : “bab”

//                                                                                                                         Explanation :
// “bab” is one valid longest subsequence present in both strings ‘s1’, ‘s2’.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findLCS(int n, int m, string &s1, string &s2)
    {
        // Write your code here.
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
        int len = dp[n][m];
        int index = len - 1;
        string ans = "";
        int i = n, j = m;
        for (int k = 0; k < len; ++k)
            ans += "$";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[index] = s1[i - 1];
                index--;
                i--;
                j--;
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
        return ans;
    }
};