// Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d.

// Examples :

// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
// Input: arr[] = [1, 1, 1, 1], d = 0
// Output: 6
// Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
// Thus there are total 6 ways for partition the array arr.
// Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
// Output: 2

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
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

public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int totalsum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalsum - d) < 0 || (totalsum - d) % 2 != 0)
            return false;
        return findWays(arr, (totalsum - d) / 2);
    }
};