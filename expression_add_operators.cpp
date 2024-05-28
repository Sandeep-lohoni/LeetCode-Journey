// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.

// Example 1:

// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
// Example 2:

// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
// Example 3:

// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

// Constraints:

// 1 <= num.length <= 10
// num consists of only digits.
// -231 <= target <= 231 - 1

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void helper(int index, string sumPath, long long sum, long prev, string num, int target, vector<string> &result)
    {
        if (index == num.size())
        {
            if (sum == target)
            {
                result.push_back(sumPath);
            }
            return;
        }
        for (int i = index; i < num.size(); i++)
        {
            if (i > index && num[index] == '0')
            {
                break;
            }
            long number = stol(num.substr(index, i - index + 1));
            string tempPath = num.substr(index, i - index + 1);
            if (index == 0)
            {
                helper(i + 1, tempPath, number, number, num, target, result);
            }
            else
            {
                helper(i + 1, sumPath + '+' + tempPath, sum + number, number, num, target, result);
                helper(i + 1, sumPath + '-' + tempPath, sum - number, -number, num, target, result);
                helper(i + 1, sumPath + '*' + tempPath, sum - prev + (prev * number), prev * number, num, target, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> result;
        helper(0, "", 0, 0, num, target, result);
        return result;
    }
};