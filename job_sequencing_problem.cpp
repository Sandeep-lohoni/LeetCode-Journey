// Given a set of n jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).
// Example 2:

// Input:
// N = 5
// Jobs = {(1,2,100),(2,1,19),(3,2,27),
//         (4,1,25),(5,1,15)}
// Output:
// 2 127
// Explanation:
// 2 jobs can be done with
// maximum profit of 127 (100+27).

// Your Task :
// You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer n and an array Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit as a list or vector of 2 elements.

// Expected Time Complexity: O(nlogn)
// Expected Auxilliary Space: O(n)

// Constraints:
// 1 <= n <= 105
// 1 <= Deadline <= n
// 1 <= Profit <= 500

// solution

#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    bool static comparator(Job val1, Job val2)
    {
        return val1.profit > val2.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comparator);
        int maxdeadline = arr[0].dead;
        for (int i = 1; i < n; ++i)
        {
            maxdeadline = max(maxdeadline, arr[i].dead);
        }
        int ans[maxdeadline + 1];
        for (int i = 0; i < maxdeadline + 1; ++i)
        {
            ans[i] = -1;
        }
        int cnt = 0;
        int totalprofit = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = arr[i].dead; j > 0; --j)
            {
                if (ans[j] == -1)
                {
                    cnt++;
                    totalprofit += arr[i].profit;
                    ans[j] = arr[i].id;
                    break;
                }
            }
        }
        return {cnt, totalprofit};
    }
};