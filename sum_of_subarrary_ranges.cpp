// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
// Example 2:

// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
// Example 3:

// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.

// Constraints:

// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109

// Follow-up: Could you find a solution with O(n) time complexity?

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        stack<int> st;
        vector<int> minprev(n, -1), minnext(n, n), maxprev(n, -1), maxnext(n, n);
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                minprev[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                minnext[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                maxprev[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                maxnext[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < n; ++i)
        {
            long long leftmin = i - minprev[i], rightmin = minnext[i] - i;
            long long leftmax = i - maxprev[i], rightmax = maxnext[i] - i;
            sum += (leftmax * rightmax - leftmin * rightmin) * nums[i];
        }
        return sum;
    }
};