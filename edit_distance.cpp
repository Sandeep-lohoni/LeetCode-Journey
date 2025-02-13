// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

//You have the following three operations permitted on a word :

//     Insert a character Delete a character Replace a character

//         Example 1 :

//     Input : word1 = "horse",
//             word2 = "ros" Output : 3 Explanation : horse->rorse(replace 'h' with 'r')
//rorse->rose(remove 'r')
//rose->ros(remove 'e')
//Example 2 :

//     Input : word1 = "intention",
//             word2 = "execution" Output : 5 Explanation : intention->inention(remove 't')
//inention->enention(replace 'i' with 'e')
//enention->exention(replace 'n' with 'x')
//exention->exection(replace 'n' with 'c')
//exection->execution(insert 'u')

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution
{

public:
// use n*m size
    int minDistance(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[n][m];
    }

    // use 2m size
    int minDistance(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int j = 0; j <= m; ++j)
            prev[j] = j;

        for (int i = 1; i <= n; ++i)
        {
            curr[0] = i;
            for (int j = 1; j <= m; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};