// You are given an array prices where prices[i] is the price of a given stock on the ith day.

//     Find the maximum profit you can achieve.You may complete at most two transactions.

//     Note : You may not engage in multiple transactions
//            simultaneously(i.e., you must sell the stock before you buy again)
//                .

//            Example 1 :

//     Input : prices = [ 3, 3, 5, 0, 0, 3, 1, 4 ] Output : 6 Explanation : Buy on day 4(price = 0) and sell on day 6(price = 3),
//             profit = 3 - 0 = 3. Then buy on day 7(price = 1) and sell on day 8(price = 4), profit = 4 - 1 = 3. Example 2 :

//     Input : prices = [ 1, 2, 3, 4, 5 ] Output : 4 Explanation : Buy on day 1(price = 1) and sell on day 5(price = 5),
//             profit = 5 - 1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time.You must sell before buying again.Example 3 :

//     Input : prices = [ 7, 6, 4, 3, 1 ] Output : 0 Explanation : In this case,
//             no transaction is done, i.e.max profit = 0.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; --ind)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {
                for (int cap = 1; cap <= 2; ++cap)
                {
                    int profit = 0;
                    if (buy == 0)
                    {
                        profit = max(dp[ind + 1][0][cap], -prices[ind] + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        profit = max(dp[ind + 1][1][cap], prices[ind] + dp[ind + 1][0][cap - 1]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][0][2];
    }

    // space optimization
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; --ind)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {
                for (int cap = 1; cap <= 2; ++cap)
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
        return curr[0][2];
    }
};