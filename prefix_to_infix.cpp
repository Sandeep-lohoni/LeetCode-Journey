// You are given a string S of size N that represents the prefix form of a valid mathematical expression. Convert it to its infix form.

// Example 1:

// Input:
// *-A/BC-/AKL
// Output:
// ((A-(B/C))*((A/K)-L))
// Explanation:
// The above output is its valid infix form.
// Your Task:

// Complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(N).

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string preToInfix(string s)
    {
        // Write your code here
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            char c = s[i];
            if (c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
            {
                string re = "(" + st.top() + c;
                st.pop();
                re += st.top() + ")";
                st.pop();
                st.push(re);
            }
            else
            {
                string temp = "";
                temp += c;
                st.push(temp);
            }
        }
        return st.top();
    }
};