// Given a string s, find the longest palindromic subsequence's length in s.

//A subsequence is a sequence that can be derived from another sequence by deleting some or
//no elements without changing the order of the remaining elements.

//Example 1 :

//Input : s = "bbbab" Output : 4 Explanation : One possible longest palindromic subsequence is "bbbb".Example 2 :

//Input : s = "cbbd" Output : 2 Explanation : One possible longest palindromic subsequence is "bb".

// solution
#include<bits/stdc++.h>
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
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};