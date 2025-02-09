// Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target.

// Examples :

// Input : arr[] = [ 3, 34, 4, 12, 5, 2 ],
// target = 9 Output : true Explanation : Here there exists a subset with target sum = 9, 4 + 3 + 2 = 9. Input : arr[] = [ 3, 34, 4, 12, 5, 2 ], target = 30 Output : false Explanation : There is no subset with target sum 30. Input : arr[] = [ 1, 2, 3 ], sum = 6 Output : true Explanation : The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

// solution

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        vector<bool> front(k + 1, 0);

        front[0] = true;
        if (arr[0] <= k)
            front[arr[0]] = true;

        for (int ind = 1; ind < n; ++ind)
        {
            vector<bool> curr(k + 1, 0);
            curr[0] = true;
            for (int target = 1; target <= k; ++target)
            {
                bool not_take = front[target];
                bool take = false;
                if (arr[ind] <= target)
                {
                    take = front[target - arr[ind]];
                }
                curr[target] = take || not_take;
            }
            front = curr;
        }
        return front[k];
    }
};