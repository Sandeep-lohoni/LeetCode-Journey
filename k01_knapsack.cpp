// You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in the knapsack.Each item is available in only one quantity.

// In other words,
// you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively.You are also given an integer capacity, which represents the knapsack capacity.Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to capacity.You cannot break an item; you must either pick the entire item or leave it (0-1 property).

// Examples :

// Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3]
// Output: 50
// Explanation: Choose the last item (value 50, weight 3) for a total value of 50.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int knapSack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = wt.size();
        vector<int> prev(W + 1, 0);
        for (int i = wt[0]; i <= W; ++i)
        {
            prev[i] = val[0];
        }
        for (int ind = 1; ind < n; ++ind)
        {
            for (int cap = W; cap >= 0; --cap)
            {
                int not_take = prev[cap];
                int take = INT_MIN;
                if (wt[ind] <= cap)
                {
                    take = val[ind] + prev[cap - wt[ind]];
                }
                prev[cap] = max(take, not_take);
            }
        }
        return prev[W];
    }
};