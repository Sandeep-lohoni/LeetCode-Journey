// Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

// Example 1:

// Input:
// N = 8
// Arr = {4, 2, 4, 5, 2, 3, 3, 1}
// Output: {5, 1}
// Explaination: 5 and 1 have odd occurrences.

// Example 2:

// Input:
// N = 8
// Arr = {1 7 5 7 5 4 7 4}
// Output: {7, 1}
// Explaination: 7 and 1 have odd occurrences.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ N ≤ 106
// 1 ≤ Arri ≤ 1012

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        // code here
        // take xor of all the numbers
        // the numbers occuring even number of times will reduce to zero
        long long int temp = 0;
        for (int i = 0; i < N; i++)
            temp = temp ^ Arr[i];
        // temp will now have the xor of two odd freq numbers(let them be a and b)
        // Get the rightmost set bit of temp (this bit is different in a and b)
        // Now divide the numbers into two groups
        // one having this bit as 1 and others as 0
        // take xor of all these groups numbers
        // notice how as we have divided the groups based on that bit that is different in a and b
        // now each group will only have one odd freq number and rest numbers will reduce to
        // zero due to their even freq thus giving us the two odd freq numbers seperately
        long long num1 = 0, num2 = 0, rightmost_setbit = temp & ~(temp - 1);
        for (int i = 0; i < N; i++)
        {
            if (Arr[i] & rightmost_setbit)
                num1 ^= Arr[i];
            else
                num2 ^= Arr[i];
        }
        vector<long long int> ans({num1, num2});
        sort(ans.rbegin(), ans.rend());
        return ans;
    }
};