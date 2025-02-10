// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins,
// return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1 :

// Input : coins = [ 1, 2, 5 ],
// amount = 11 Output : 3 Explanation : 11 = 5 + 5 + 1 Example 2 :

// Input : coins = [2],
// amount = 3 Output : -1 Example 3 :

// Input : coins = [1],
// amount = 0 Output : 0

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; ++i)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }
        for (int ind = 1; ind < n; ++ind)
        {
            for (int target = 0; target <= amount; ++target)
            {
                int not_take = dp[ind - 1][target];
                int take = 1e9;
                if (coins[ind] <= target)
                {
                    take = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(take, not_take);
            }
        }
        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};
