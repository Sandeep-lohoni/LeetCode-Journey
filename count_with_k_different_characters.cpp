// You are given a string 'str' of lowercase alphabets and an integer 'k' .

// Your task is to return the count all the possible substrings that have exactly 'k' distinct characters.

// For example:

// 'str' = abcad and 'k' = 2.

// We can see that the substrings {ab, bc, ca, ad} are the only substrings with 2 distinct characters.

// Therefore, the answer will be 4.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// aacfssa
// 3
// Sample Output 1 :
// 5
// Explanation of The Sample Input 1:
// Given 'str' = “aacfssa”. We can see that the substrings with only 3 distinct characters are {aacf, acf, cfs, cfss, fssa}.

// Therefore, the answer will be 5.
// Sample Input 2 :
// qffds
// 4
// Sample Output 2 :
// 1
// Constraints:
// 1 <= |str| <= 10^5
// 1 <= k <= 26

// Time Limit: 1 second

// solution
#include <bits/stdc++.h>
using namespace std;
int countSubStrings(string str, int k)
{
    // Write your code here.
    int n = str.size();
    int rel = 0;
    int cnt[26];
    for (int i = 0; i < n; ++i)
    {
        int distcount = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; ++j)
        {
            if (cnt[str[j] - 'a'] == 0)
                distcount++;
            cnt[str[j] - 'a']++;
            if (distcount == k)
                rel++;
            if (distcount > k)
                break;
        }
    }
    return rel;
}
