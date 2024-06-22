// Given a string s, find the length of the longest
// substring
//  without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> arr(256, -1);
        int left = 0, right = 0;
        int maxlen = 0;
        while (right < n)
        {
            if (arr[s[right]] != -1)
            {
                if (arr[s[right]] >= left)
                {
                    left = arr[s[right]] + 1;
                }
            }
            maxlen = max(maxlen, right - left + 1);
            arr[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};