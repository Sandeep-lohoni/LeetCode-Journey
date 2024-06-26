// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

// 1 <= n <= 8

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> v;
    void generate(string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            v.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            generate(s, open - 1, close);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                generate(s, open, close - 1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string s;
        generate(s, n, n);
        return v;
    }
};
