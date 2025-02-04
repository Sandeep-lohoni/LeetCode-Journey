// You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed.All houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

//Given an integer array nums representing the amount of money of each house,
//return the maximum amount of money you can rob tonight without alerting the police.

//Example 1 :

//Input : nums = [ 2, 3, 2 ] Output : 3 Explanation : You cannot rob house 1(money = 2) and then rob house 3(money = 2),
//because they are adjacent houses.Example 2 :

//Input : nums = [ 1, 2, 3, 1 ] Output : 4 Explanation : Rob house 1(money = 1) and then rob house 3(money = 3).Total amount you can rob = 1 + 3 = 4. Example 3 :

//Input : nums = [ 1, 2, 3 ] Output : 3

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int robber1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick = pick + dp[i - 2];
            }
            int not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }
        return dp[n - 1];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp1, temp2;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(robber1(temp1), robber1(temp2));
    }
};