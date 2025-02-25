// You are given a string s.You can convert s to a palindrome by adding characters in front of it.

//     Return the shortest palindrome you can find by performing this transformation.

//     Example 1 :

//     Input : s = "aacecaaa" Output : "aaacecaaa" Example 2 :

//     Input : s = "abcd" Output : "dcbabcd"

// solution
#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void computeLPS(const string &pattern, vector<int> &lps)
    {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    string shortestPalindrome(string s)
    {
        string rev = s;
        reverse(begin(rev), end(rev));
        string temp = s + "-" + rev;
        vector<int> LPS(temp.size(), 0);
        computeLPS(temp, LPS);
        int longestLPSlength = LPS[temp.length() - 1];
        string culprit = rev.substr(0, s.length() - longestLPSlength);
        return culprit + s;
    }
};