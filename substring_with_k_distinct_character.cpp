// Given a string s of lowercase alphabets, count all possible substrings(not necessarily distinct) that have exactly k distinct characters.

//                                          Examples :

//     Input : s = "aba",
//             k = 2 Output : 3 Explanation : The substrings are : "ab", "ba" and "aba".Input : s = "abaaca", k = 1 Output : 7 Explanation : The substrings are : "a", "b", "a", "aa", "a", "c", "a".Input : s = "cdad", k = 4 Output : 0

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int atmostk(string &s, int k)
    {
        if (k <= 0)
            return 0;
        int i = 0, j = 0, cnt = 0, res = 0;
        int mp[26] = {0};
        while (j < s.length())
        {
            mp[s[j] - 'a']++;
            if (mp[s[j] - 'a'] == 1)
                cnt++;
            while (cnt > k)
            {
                mp[s[i] - 'a']--;
                if (mp[s[i] - 'a'] == 0)
                    cnt--;
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
    }

public:
    int countSubstr(string &s, int k)
    {
        // code here.
        return atmostk(s, k) - atmostk(s, k - 1);
    }
};