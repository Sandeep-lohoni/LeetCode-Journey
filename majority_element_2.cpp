// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
                cnt1++;
            else if (el2 == nums[i])
                cnt2++;
            else
                cnt1--, cnt2--;
        }
        vector<int> temp;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (el1 == nums[i])
                cnt1++;
            if (el2 == nums[i])
                cnt2++;
        }
        int mini = (int)(nums.size() / 3) + 1;
        if (cnt1 >= mini)
            temp.push_back(el1);
        if (cnt2 >= mini)
            temp.push_back(el2);
        return temp;
    }
};