// Given an integer N, print all the divisors of N in the ascending order.

// Example 1:

// Input : 20
// Output: 1 2 4 5 10 20
// Explanation: 20 is completely
// divisible by 1, 2, 4, 5, 10 and 20.

// Example 2:

// Input: 21191
// Output: 1 21191
// Explanation: As 21191 is a prime number,
// it has only 2 factors(1 and the number itself).

// Your Task:

// Your task is to complete the function print_divisors() which takes N as input parameter and prints all the factors of N as space seperated integers in sorted order. You don't have to print any new line after printing the desired output. It will be handled in driver code.

// Expected Time Complexity: O(sqrt(N))
// Expected Space Complexity: O(sqrt(N))

// Constraints:
// 1 <= N <= 105

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void print_divisors(int n)
    {
        // Code here.
        vector<int> list;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                list.push_back(i);
                if (n % i != i)
                {
                    list.push_back(n / i);
                }
            }
        }
        sort(list.begin(), list.end());
        for (int i = 0; i < list.size(); ++i)
        {
            cout << list[i] << " ";
        }
    }
};