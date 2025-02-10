// Given a rod of length n(size of price) inches and an array of prices, price.price[i] denotes the value of a piece of length i.Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Example :

//     Input : price[] = [ 1, 5, 8, 9, 10, 17, 17, 20 ] Output : 22 Explanation : The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6,
//             i.e., 5 + 17 = 22. Input : price[] = [ 3, 5, 8, 9, 10, 17, 17, 20 ] Output : 24 Explanation : The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8 * price[1] = 8 * 3 = 24. Input : price[] = [ 1, 10, 3, 1, 3, 1, 5, 9 ] Output : 40

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            prev[i] = i * price[0];
        }
        for (int ind = 1; ind < n; ++ind)
        {
            for (int N = 0; N <= n; ++N)
            {
                int not_take = prev[N];
                int take = INT_MIN;
                int rodlen = ind + 1;
                if (rodlen <= N)
                    take = price[ind] + curr[N - rodlen];
                curr[N] = max(not_take, take);
            }
            prev = curr;
        }
        return prev[n];
    }
};