// You are given a positive number N. Using the concept of Sieve, compute its prime factorisation.

// Example:

// Input:
// N = 12246
// Output:
// 2 3 13 157
// Explanation:
// 2*3*13*157 = 12246 = N.
// Your Task:

// Comple the function findPrimeFactors(), which takes a positive number N as input and returns a vector consisting of prime factors. You should implement Sieve algorithm to solve this problem.

// Expected Time Complexity: O(Nlog(log(N)).

// Expected Auxiliary Space: O(N).

// Constraints:

// 1<=N<=2*105

// solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prime(N + 1);
    void sieve()
    {
        for (int i = 1; i <= N; ++i)
        {
            prime[i] = i;
        }
        for (int i = 2; i * i < N; ++i)
        {
            if (prime[i] = i)
            {
                for (int j = i * i; j <= N; j += i)
                {
                    if (prime[j] == j)
                    {
                        prime[j] = i;
                    }
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N)
    {
        // Write your code here
        vector<int> ans;
        for (int i = 0; i < N; ++i)
        {
            int a = prime[i];
            while (a != 1)
            {
                ans.push_back(prime[a]);
                a = a / prime[a];
            }
        }
        return ans;
    }
};