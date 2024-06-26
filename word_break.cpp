// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[301];
    int helper(int i, string s, set<string> &wordDict)
    {
        if (i == s.size())
            return 1;
        string temp;
        if (dp[i] != -1)
            return dp[i];
        for (int j = i; j < s.size(); ++j)
        {
            temp += s[j];
            if (wordDict.find(temp) != wordDict.end())
            {
                if (helper(j + 1, s, wordDict))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st;
        memset(dp, -1, sizeof(dp));
        for (auto a : wordDict)
            st.insert(a);
        return helper(0, s, st);
    }
};