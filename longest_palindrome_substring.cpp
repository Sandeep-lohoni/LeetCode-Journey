// Given a string s, return the longest
// palindromic

// substring
//  in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;
        int start = 0;
        int maxlen = -1;
        for (int i = 0; i < n; ++i)
        {
            int l = i, r = i;
            while (l >= 0 && r < n)
            {
                if (s[l] == s[r])
                {
                    l--, r++;
                }
                else
                    break;
            }
            int len = r - l - 1;
            if (len > maxlen)
            {
                maxlen = len;
                start = l + 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int l = i, r = i + 1;
            while (l >= 0 && r < n)
            {
                if (s[l] == s[r])
                {
                    l--, r++;
                }
                else
                    break;
            }
            int len = r - l - 1;
            if (len > maxlen)
            {
                maxlen = len;
                start = l + 1;
            }
        }
        return s.substr(start, maxlen);
    }
};