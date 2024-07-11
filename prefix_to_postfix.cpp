// You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

// Example:

// Input:
// *-A/BC-/AKL
// Output:
// ABC/-AK/L-*
// Explanation:
// The above output is its valid postfix form.
// Your Task:

// Complete the function preToPost(string pre_exp), which takes a prefix string as input and returns its postfix form.

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// Constraints:

// 3<=pre_exp.length()<=100

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string preToPost(string s)
    {
        stack<string> st;
        string res = "";
        for (int i = s.size() - 1; i >= 0; --i)
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
                res = s1 + s2 + s[i];
                st.push(res);
            }
        }
        return st.top();
    }
};