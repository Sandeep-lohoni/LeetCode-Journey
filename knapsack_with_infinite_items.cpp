// Given a set of items, each with a weight and a value, represented by the array wt and val respectively.Also, a knapsack with a weight limit capacity.The task is to fill the knapsack in such a way that we can get the maximum profit.Return the maximum profit.Note : Each item can be taken any number of times.

// Examples :

//     Input : val = [ 1, 1 ],
//             wt = [ 2, 1 ], capacity = 3 Output : 3 Explanation : The optimal choice is to pick the 2nd element 3 times.Input : val[] = [ 6, 1, 7, 7 ], wt[] = [ 1, 3, 4, 5 ], capacity = 8 Output : 48 Explanation : The optimal choice is to pick the 1st element 8 times.Input : val[] = [ 6, 8, 7, 100 ], wt[] = [ 2, 3, 4, 5 ], capacity = 1 Output : 0 Explanation : We can't pick any element .hence, total profit is 0.
// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = val.size();
        vector<int> prev(capacity + 1, 0);

        for (int i = 0; i <= capacity; ++i)
        {
            prev[i] = ((int)i / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ++ind)
        {
            for (int W = 0; W <= capacity; ++W)
            {
                int not_take = prev[W];
                int take = -1e9;
                if (wt[ind] <= W)
                {
                    take = val[ind] + prev[W - wt[ind]];
                }
                prev[W] = max(take, not_take);
            }
        }
        return prev[capacity];
    }
};