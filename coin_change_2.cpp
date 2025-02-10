// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//     Return the number of combinations that make up that amount.If that amount of money cannot be made up by any combination of the coins,
//     return 0.

//You may assume that you have an infinite number of each kind of coin.

//The answer is guaranteed to fit into a signed 32 -
//bit integer.

//Example 1 :

//     Input : amount = 5,
//             coins = [ 1, 2, 5 ] Output : 4 Explanation : there are four ways to make up the amount : 5 = 5 5 = 2 + 2 + 1 5 = 2 + 1 + 1 + 1 5 = 1 + 1 + 1 + 1 + 1 Example 2 :

//     Input : amount = 3,
//             coins = [2] Output : 0 Explanation : the amount of 3 cannot be made up just with coins of 2. Example 3 :

//     Input : amount = 10,
//             coins = [10] Output : 1

// solution

#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int i = 0; i <= amount; ++i)
        {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }
        for (int ind = 1; ind < n; ++ind)
        {
            for (int target = 0; target <= amount; ++target)
            {
                int not_take = prev[target];
                int take = 0;
                if (coins[ind] <= target)
                {
                    take = curr[target - coins[ind]];
                }
                if (INT_MAX - take >= not_take)
                {
                    curr[target] = take + not_take;
                }
                else
                {
                    curr[target] = INT_MAX;
                }
            }
            prev = curr;
        }
        return prev[amount];
    }
};