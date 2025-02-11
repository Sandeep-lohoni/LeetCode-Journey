// Given two strings text1 and text2, return the length of their longest common subsequence.If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some
// characters(can be none) deleted without changing the relative order of the remaining characters.

// For example,
//"ace" is a subsequence of "abcde".A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1 :

// Input : text1 = "abcde",
// text2 = "ace" Output : 3 Explanation : The longest common subsequence is "ace" and its length is 3. Example 2 :

// Input : text1 = "abc",
// text2 = "abc" Output : 3 Explanation : The longest common subsequence is "abc" and its length is 3. Example 3 :

// Input : text1 = "abc",
// text2 = "def" Output : 0 Explanation : There is no such common subsequence, so the result is 0.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
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
};