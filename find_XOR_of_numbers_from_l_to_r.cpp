// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Example:

// Input:
// L = 4, R = 8
// Output:
// 8
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
// Your Task:

// Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

// Expected Time Complexity: O(1).

// Expected Auxiliary Space: O(1).

// Constraints:

// 1<=l<=r<=109

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int n)
    {
        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }
    int findXOR(int l, int r)
    {
        // complete the function here
        int first = helper(l - 1);
        int second = helper(r);
        return first ^ second;
    }
};