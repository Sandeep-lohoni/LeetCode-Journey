// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0;
        int right = 0;
        int minlen = INT_MAX;
        int cnt = 0;
        int sindex = -1;
        vector<int> mpp(128, 0);
        for (int i = 0; i < t.size(); ++i)
        {
            mpp[t[i]]++;
        }
        while (right < s.size())
        {
            if (mpp[s[right]] > 0)
            {
                cnt++;
            }
            mpp[s[right]]--;
            while (cnt == t.size())
            {
                if ((right - left + 1) < minlen)
                {
                    minlen = right - left + 1;
                    sindex = left;
                }
                mpp[s[left]]++;
                if (mpp[s[left]] > 0)
                    cnt--;
                left++;
            }
            right++;
        }
        return (sindex == -1 ? "" : s.substr(sindex, minlen));
    }
};