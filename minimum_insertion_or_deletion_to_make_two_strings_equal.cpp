// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step,
//      you can delete exactly one character in either string.

//     Example 1 :

//     Input : word1 = "sea",
//             word2 = "eat" Output : 2 Explanation : You need one step to make "sea" to "ea" and another step to make "eat" to "ea".Example 2 :

//     Input : word1 = "leetcode",
//             word2 = "etco" Output : 4

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    curr[ind2] = 1 + prev[ind2 - 1];
                else
                    curr[ind2] = max(curr[ind2 - 1], prev[ind2]);
            }
            prev = curr;
        }
        return prev[m];
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int e = longestCommonSubsequence(word1, word2);
        return (n - e + m - e);
    }
};