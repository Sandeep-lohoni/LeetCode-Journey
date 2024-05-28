// Given an integer array nums that may contain duplicates, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> &nums, vector<int> &sub, vector<vector<int>> &mp, int ind)
    {
        int n = nums.size();
        mp.push_back(sub);
        for (int i = ind; i < n; ++i)
        {
            if (i != ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            sub.push_back(nums[i]);
            helper(nums, sub, mp, i + 1);
            sub.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> sub;
        vector<vector<int>> mp;
        sort(nums.begin(), nums.end());
        helper(nums, sub, mp, 0);
        return mp;
    }
};