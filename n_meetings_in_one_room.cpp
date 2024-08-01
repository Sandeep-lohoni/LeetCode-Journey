// There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Return the maximum number of meetings that can be held in the meeting room.

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Examples :

// Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
// Input: n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
// Output: 1
// Explanation: Only one meetings can be held with given start and end timings.
// Expected Time Complexity : O(n*Logn)
// Expected Auxilliary Space : O(n)

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ start[i] < end[i] ≤ 105

// solution

#include <bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
class Solution
{
public:
    static bool compare(struct meeting m1, meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; ++i)
        {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i + 1;
        }
        sort(meet, meet + n, compare);
        int lastused = meet[0].end;
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (meet[i].start > lastused)
            {
                lastused = meet[i].end;
                cnt++;
            }
        }
        return cnt;
    }
};