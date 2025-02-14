// Given a set of distinct positive integers nums, return the largest subset answer such that every pair(answer[i], answer[j]) of elements in this subset satisfies :

//     answer[i] %
//     answer[j] == 0,
//     or
//         answer[j] % answer[i] == 0 If there are multiple solutions,
//     return any of them.

//            Example 1 :

//     Input : nums = [ 1, 2, 3 ] Output : [ 1, 2 ] Explanation : [ 1, 3 ] is also accepted.Example 2 :

//     Input : nums = [ 1, 2, 4, 8 ] Output : [ 1, 2, 4, 8 ]

//Constraints :

//1 <= nums.length <= 1000 1 <= nums[i] <= 2 * 109 All the integers in nums are unique.

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        sort(arr.begin(), arr.end());
        for (int ind = 0; ind < n; ++ind)
        {
            hash[ind] = ind;
            for (int prev_ind = 0; prev_ind < ind; ++prev_ind)
            {
                if (arr[ind] % arr[prev_ind] == 0 && 1 + dp[prev_ind] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev_ind];
                    hash[ind] = prev_ind;
                }
            }
        }

        int ans = 0;
        int lastindex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                lastindex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(arr[lastindex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};