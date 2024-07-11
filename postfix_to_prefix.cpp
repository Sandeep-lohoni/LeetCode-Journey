// You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

// Example 1:

// Input:
// ABC/-AK/L-*
// Output:
// *-A/BC-/AKL
// Explanation:
// The above output is its valid prefix form.

// Example 2:

// Input:
// ab+
// Output:
// +ab
// Explanation:
// The above output is its valid prefix form.
// Your Task:

// Complete the function string postToPre(string post_exp), which takes a postfix string as input and returns its prefix form.

// Expected Time Complexity: O(post_exp.length()).

// Expected Auxiliary Space: O(post_exp.length()).

// Constraints:

// 3<=post_exp.length()<=16000

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string postToPre(string s)
    {
        // Write your code here
        stack<string> st;
        string rel = "";
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                rel = s[i] + s2 + s1;
                st.push(rel);
            }
        }
        return st.top();
    }
};