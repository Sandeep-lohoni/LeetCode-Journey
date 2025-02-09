// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Example 1 :

// Input : nums = [ 1, 5, 11, 5 ] Output : true Explanation : The array can be partitioned as[1, 5, 5] and[11].Example 2 :

// Input : nums = [ 1, 2, 3, 5 ] Output : false Explanation : The array cannot be partitioned into equal sum subsets.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[ind] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool not_take = f(ind - 1, target, nums, dp);
        bool take = false;
        if (nums[ind] <= target)
        {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take || not_take;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
        return f(n - 1, sum / 2, nums, dp);
    }
};