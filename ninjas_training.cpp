// Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

// Example:

// Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
// Output: 11
// Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
// Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
// Output: 6
// Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
// Input: arr[]= [[4, 2, 6]]
// Output: 6
// Explanation: Geek will learn a new move to make his merit points as 6.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int memo(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &arr)
    {
        if (dp[day][last] != -1)
            return dp[day][last];
        if (day == 0)
        {
            int maxi = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i != last)
                    maxi = max(maxi, arr[day][i]);
            }
            return dp[day][last] = maxi;
        }
        int maxi = 0;
        for (int i = 0; i <= 2; ++i)
        {
            if (i != last)
            {
                int activity = arr[day][i] + memo(day - 1, i, dp, arr);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return memo(n - 1, 3, dp, arr);
    }
};