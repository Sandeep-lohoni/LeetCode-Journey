// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

//                                                                                                         Find the maximum profit you can achieve.You may complete at most k transactions : i.e.you may buy at most k times and sell at most k times.

// Note : You may not engage in multiple transactions
// simultaneously(i.e., you must sell the stock before you buy again)
//                                                                                                                                                                                                       .

// Example 1 :

//     Input : k = 2,
//             prices = [ 2, 4, 1 ] Output : 2 Explanation : Buy on day 1(price = 2) and sell on day 2(price = 4), profit = 4 - 2 = 2. Example 2 :

//     Input : k = 2,
//             prices = [ 3, 2, 6, 5, 0, 3 ] Output : 7 Explanation : Buy on day 2(price = 2) and sell on day 3(price = 6), profit = 6 - 2 = 4. Then buy on day 5(price = 0) and sell on day 6(price = 3), profit = 3 - 0 = 3.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (ind == prices.size() || cap == 0)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        int profit = 0;
        if (buy == 0)
        {
            profit = max(f(ind + 1, 0, cap, prices, dp),
                         -prices[ind] + f(ind + 1, 1, cap, prices, dp));
        }
        else
        {
            profit = max(f(ind + 1, 1, cap, prices, dp),
                         prices[ind] + f(ind + 1, 0, cap - 1, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 0, k, prices, dp);
    }

    // space optimization
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int ind = n - 1; ind >= 0; --ind)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {
                for (int cap = 1; cap <= k; ++cap)
                {
                    int profit = 0;
                    if (buy == 0)
                    {
                        profit = max(ahead[0][cap], -prices[ind] + ahead[1][cap]);
                    }
                    else
                    {
                        profit = max(ahead[1][cap], prices[ind] + ahead[0][cap - 1]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return curr[0][k];
    }
};