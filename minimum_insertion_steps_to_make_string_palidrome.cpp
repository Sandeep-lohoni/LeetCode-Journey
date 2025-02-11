// Given a string s.In one step you can insert any character at any index of the string.

//Return the minimum number of steps to make s palindrome.

//     A Palindrome String is one that reads the same backward as well as forward.

//     Example 1 :

//     Input : s = "zzazz" Output : 0 Explanation : The string "zzazz" is already palindrome we do not need any insertions.Example 2 :

//     Input : s = "mbadm" Output : 2 Explanation : String can be "mbdadbm" or "mdbabdm".Example 3 :

//     Input : s = "leetcode" Output : 5 Explanation : Inserting 5 characters the string becomes "leetcodocteel".

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution {
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
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        return n - longestCommonSubsequence(s,t);
    }
};