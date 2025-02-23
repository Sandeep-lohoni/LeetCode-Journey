// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.A reversal means changing '{' to '}' or vice - versa.

//Example 1 :

//     Input : S = "}{{}}{{{" Output : 3 Explanation : One way to balance is : "{{{}}{}}".There is no balanced sequence
//that can be formed in lesser reversals.Example 2 :

//     Input : S = "{{}{{{}{{}}{{" Output : -1 Explanation : There's no way we can balance this sequence of braces.Your Task : You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as the input parameter and returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

// solution

#include <bits/stdc++.h>
using namespace std;

class Solution{
    int countRev(string s)
    {
        // your code here
        if (s.length() % 2 != 0)
            return -1;
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    st.push(ch);
            }
        }
        int open = 0, close = 0;
        while (!st.empty())
        {
            if (st.top() == '{')
                open++;
            else
                close++;
            st.pop();
        }
        int ans = (open + 1) / 2 + (close + 1) / 2;
        return ans;
    }



    // 1 space
    int countRev(string s)
    {
        // your code here
        if (s.length() % 2 != 0)
            return -1;
        int open = 0, close = 0;
        for (char ch : s)
        {
            if (ch == '{')
            {
                open++;
            }
            else
            {
                if (open == 0)
                {
                    close++;
                }
                else
                    open--;
            }
        }
        int ans = (open + 1) / 2 + (close + 1) / 2;
        return ans;
    }
};