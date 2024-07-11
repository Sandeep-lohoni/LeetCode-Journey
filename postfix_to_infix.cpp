// You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

// Example:

// Input:
// ab*c+
// Output:
// ((a*b)+c)
// Explanation:
// The above output is its valid infix form.
// Your Task:

// Complete the function string postToInfix(string post_exp), which takes a postfix string as input and returns its infix form.

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=post_exp.length()<=104

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string postToInfix(string s)
    {
        // Write your code here
        stack<string> st;
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
                st.push('(' + s2 + s[i] + s1 + ')');
            }
        }
        return st.top();
    }
};