// You are given an integer array nums and an integer target.

//     You want to build an expression out of nums by adding one of the symbols '+' and
//'-' before each integer in nums and then concatenate all the integers.

//     For example,
//     if nums = [ 2, 1 ], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".Return the number of different expressions that you can build, which evaluates to target.

// Example 1 :

//     Input : nums = [ 1, 1, 1, 1, 1 ],
//        target = 3 Output : 5 Explanation : There are 5 ways to assign symbols to make the sum of nums be target 3. - 1 + 1 + 1 + 1 + 1 = 3 + 1 - 1 + 1 + 1 + 1 = 3 + 1 + 1 - 1 + 1 + 1 = 3 + 1 + 1 + 1 - 1 + 1 = 3 + 1 + 1 + 1 + 1 - 1 = 3 Example 2 :

//     Input : nums = [1],
//        target = 1 Output : 1

// solution:

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
private:
    int mod = (int)1e9 + 7;

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (num[0] == 0)
            dp[0][0] = 2; // 2 cases -pick and not pick
        else
            dp[0][0] = 1; // 1 case - not pick

        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1; // 1 case -pick

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= tar; target++)
            {

                int notTaken = dp[ind - 1][target];

                int taken = 0;
                if (num[ind] <= target)
                    taken = dp[ind - 1][target - num[ind]];

                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n - 1][tar];
    }
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalsum - d) < 0 || (totalsum - d) % 2 != 0)
            return false;
        return findWays(arr, (totalsum - d) / 2);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return countPartitions(nums, target);
    }
};