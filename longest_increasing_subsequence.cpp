// Given an integer array nums, return the length of the longest strictly increasing subsequence.

//                                     Example 1 :

//     Input : nums = [ 10, 9, 2, 5, 3, 7, 101, 18 ] Output : 4 Explanation : The longest increasing subsequence is[2, 3, 7, 101],
//             therefore the length is 4. Example 2 :

//     Input : nums = [ 0, 1, 0, 3, 2, 3 ] Output : 4 Example 3 :

//     Input : nums = [ 7, 7, 7, 7, 7, 7, 7 ] Output : 1

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    // memoization
private:
    int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        int not_take = 0 + f(ind + 1, prev_ind, nums, dp);
        int take = -1e9;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + f(ind + 1, ind, nums, dp);
        }
        return dp[ind][prev_ind + 1] = max(take, not_take);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }

    // tabulation
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; --ind)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; --prev_ind)
            {
                int not_take = 0 + dp[ind + 1][prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prev_ind + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
    // space optimizaiton
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; --ind)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; --prev_ind)
            {
                int not_take = 0 + next[prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                {
                    take = 1 + next[ind + 1];
                }
                curr[prev_ind + 1] = max(take, not_take);
            }
            next = curr;
        }
        return curr[0];
    }
};