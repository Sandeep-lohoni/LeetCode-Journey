// Given an array arr of non - negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.
// Examples :
//     Input : arr[] = [ 5, 2, 3, 10, 6, 8 ],
// target = 10 Output : 3 Explanation : The subsets{5, 2, 3}, {2, 8}, and{10} sum up to the target 10. Input : arr[] = [ 2, 5, 1, 4, 3 ], target = 10 Output : 3 Explanation : The subsets{2, 1, 4, 3}, {5, 1, 4}, and{2, 5, 3} sum up to the target 10. Input : arr[] = [ 5, 7, 8 ], target = 3 Output : 0 Explanation : There are no subsets of the array that sum up to the target 3. Input : arr[] = [ 35, 2, 8, 22 ], target = 0 Output : 1 Explanation : The empty subset is the only subset with a sum of 0.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (nums[0] == target || target == 0)
                return 1;
            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int not_take = f(ind - 1, target, nums, dp);
        int take = 0;
        if (nums[ind] <= target)
        {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take + not_take;
    }

public:
    int perfectSum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, arr, dp);
    }
};