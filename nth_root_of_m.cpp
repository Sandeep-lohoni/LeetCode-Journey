// You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.

// Note:
// 'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.

// Example:
// Input: ‘n’ = 3, ‘m’ = 27

// Output: 3

// Explanation:
// 3rd Root of 27 is 3, as (3)^3 equals 27.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3 27

// Sample Output 1:
// 3

// Explanation For Sample Input 1:
// 3rd Root of 27 is 3, as (3)^3 equals 27.

// Sample Input 2:
// 4 69

// Sample Output 2:
// -1

// Explanation For Sample Input 2:
// 4th Root of 69 is not an integer, hence -1.

// Expected Time Complexity:
// Try to do this in O(log(n+m)).

// Constraints:
// 1 <= n <= 30
// 1 <= m <= 10^9

// Time Limit: 1 sec.

// solution
#include <bits/stdc++.h>
using namespace std;
int factor(int num, int n, int m)
{
  long long ans = 1;
  for (int i = 0; i < n; ++i)
  {
    ans *= num;
    if (ans > m)
      return 2;
  }
  if (ans == m)
    return 1;
  return 0;
}
int NthRoot(int n, int m)
{
  // Write your code here.
  int low = 1;
  int high = m;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int nm = factor(mid, n, m);
    if (nm == 1)
      return mid;
    else if (nm == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}