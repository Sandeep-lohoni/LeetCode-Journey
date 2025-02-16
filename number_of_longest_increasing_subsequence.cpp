// Given an integer array nums, return the number of longest increasing subsequences.

//Notice that the sequence has to be strictly increasing.

//Example 1 :

//     Input : nums = [ 1, 3, 5, 4, 7 ] Output : 2 Explanation : The two longest increasing subsequences are[1, 3, 4, 7] and [ 1, 3, 5, 7 ].Example 2 :

//     Input : nums = [ 2, 2, 2, 2, 2 ] Output : 5 Explanation : The length of the longest increasing subsequence is 1,
//             and there are 5 increasing subsequences of length 1, so output 5.

// solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        for (int i = 0; i < n; ++i)
        {
            for (int prevind = 0; prevind < i; ++prevind)
            {
                if (nums[prevind] < nums[i] && 1 + dp[prevind] > dp[i])
                {
                    dp[i] = 1 + dp[prevind];
                    cnt[i] = cnt[prevind];
                }
                else if(nums[prevind] < nums[i] && 1+dp[prevind] == dp[i]){
                    cnt[i] += cnt[prevind];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int numberofLIS = 0;
        for(int i=0;i<n;++i){
            if(dp[i]==maxi) numberofLIS +=cnt[i];
        }
        return numberofLIS;
    }
};