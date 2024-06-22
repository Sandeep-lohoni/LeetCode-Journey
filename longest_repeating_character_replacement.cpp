// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int left = 0, right = 0;
        int maxfreq = 0, maxlen = 0;
        vector<int> freq(26, 0);
        while (right < n)
        {
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq, freq[s[right] - 'A']);
            if (((right - left + 1) - maxfreq) > k)
            {
                freq[s[left] - 'A']--;
                maxfreq = 0;
                for (int i = 0; i < 26; ++i)
                {
                    maxfreq = max(maxfreq, freq[i]);
                }
                left++;
            }
            if (((right - left + 1) - maxfreq) <= k)
            {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};
