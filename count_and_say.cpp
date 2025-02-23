// The count - and - say sequence is a sequence of digit strings defined by the recursive formula :

//     countAndSay(1) = "1" countAndSay(n) is the run - length encoding of countAndSay(n - 1).Run - length encoding(RLE)
// is a string compression method that works by replacing consecutive identical characters(repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters(length of the run).For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11".Thus the compressed string becomes "23321511".

// Given a positive integer n,
//      return the nth element of the count - and - say sequence.

// Example 1 :

//     Input : n = 4

// Output : "1211"

// Explanation :

//     countAndSay(1) = "1" countAndSay(2) = RLE of "1" = "11" countAndSay(3) = RLE of "11" = "21" countAndSay(4) = RLE of "21" = "1211" Example 2 :

//     Input : n = 1

// Output : "1"
// Explanation :

//     This is the base case.

//     Constraints:

// 1 <= n <= 30

// solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string previous = countAndSay(n - 1);
        string result = "";
        int length = previous.size();
        for (int i = 0; i < length; ++i)
        {
            int count = 1;
            while (i < length - 1 && previous[i] == previous[i + 1])
            {
                count++;
                i++;
            }
            result += to_string(count) + previous[i];
        }
        return result;
    }

    // dp solution

private:
    string getNextSequence(const string &s)
    {
        string result;
        int len = s.size();

        for (int i = 0; i < len; ++i)
        {
            int count = 1;
            while (i < len - 1 && s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            result += to_string(count) + s[i];
        }

        return result;
    }

public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        vector<string> memo(n);
        memo[0] = "1";
        for (int i = 1; i < n; ++i)
        {
            memo[i] = getNextSequence(memo[i - 1]);
        }
        return memo[n - 1];
    }
};
