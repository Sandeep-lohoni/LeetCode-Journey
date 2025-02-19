// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch1 = s[i];
            char ch2 = t[i];
            if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)
            {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};