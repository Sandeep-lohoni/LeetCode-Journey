// You are given two strings s1 and s2.Your task is to find the length of the longest common substring among the given strings.

//     Examples :

//     Input : s1 = "ABCDGH",
//             s2 = "ACDGHR" Output : 4 Explanation : The longest common substring is "CDGH" with a length of 4. Input : s1 = "abc", s2 = "acb" Output : 1 Explanation : The longest common substrings are "a", "b", "c" all having length 1. Input : s1 = "YZ", s2 = "yz" Output : 0

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = 0;

        int ans = 0;
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                    ans = max(ans, dp[ind1][ind2]);
                }
                else
                    dp[ind1][ind2] = 0;
            }
        }
        return ans;
    }
};