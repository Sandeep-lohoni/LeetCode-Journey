// You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.

// For Example
// 'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
// Subset [2, 3] has sum equal to 'K'.
// So our answer is True.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 4 13
// 4 3 5 2
// Sample Output 1 :
// No
// Sample Input 2 :
// 5 14
// 4 2 5 6 7
// Sample Output 2 :
// Yes
// Constraints :
// 1 <= 'N' <= 10^3
// 1 <= 'A[i]' <= 10^3
// 1 <= 'K' <= 10^3

// solution
#include <bits/stdc++.h>
using namespace std;
bool helper(int start, int &end, long long sum, int k, vector<int> &a)
{
    if (sum == k)
    {
        return true;
    }
    if (sum > k)
        return false;
    if (start == end)
    {
        if (sum == k)
        {
            return true;
        }
        return false;
    }
    sum += a[start];
    if (helper(start + 1, end, sum, k, a) == true)
        return true;
    sum -= a[start];
    if (helper(start + 1, end, sum, k, a) == true)
        return true;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    long long sum = 0;
    helper(0, n, sum, k, a);
}