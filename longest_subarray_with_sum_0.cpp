// Ninja is given an array ‘Arr’ of size ‘N’. You have to help him find the longest subarray of ‘Arr’, whose sum is 0. You must return the length of the longest subarray whose sum is 0.

// For Example:
// For N = 5, and Arr = {1, -1, 0, 0, 1},
// We have the following subarrays with zero sums:
// {{1, -1}, {1, -1, 0}, {1, -1, 0, 0}, {-1, 0, 0, 1}, {0}, {0, 0}, {0}}
// Among these subarrays, {1, -1, 0, 0} and {-1, 0, 0, 1} are the longest subarrays with their sum equal to zero. Hence the answer is 4.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// 1 0 -1 1
// Sample Output 1:
// 3
// Explanation of Sample Input 1:
// The subarrays with sums equal to zero are: {{1, 0, -1}, {0}, {0, -1, 1}, {-1, 1}}.
// Among these, {1, 0, -1} and {0, -1, 1} are the longest with length equal to 3.
// Hence the answer is 3.
// Sample Input 2:
// 2
// 1 1
// Sample Output 2:
// 0
// Constraints:
// 1 <= N <= 10^5
// -10^9 <= Arr[i] <= 10^9

// The sum of ‘N’ over all test cases is less than or equal to 10^5.
// Time Limit: 1 sec.

// solution
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int> &nums)
{
	// Write your code here.
	map<int, int> ans;
	int n = nums.size();
	int sum = 0;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += nums[i];
		if (sum == 0)
		{
			maxi = i + 1;
		}
		else
		{
			if (ans.find(sum) != ans.end())
			{
				maxi = max(maxi, i - ans[sum]);
			}
			else
			{
				ans[sum] = i;
			}
		}
	}
	return maxi;
}
