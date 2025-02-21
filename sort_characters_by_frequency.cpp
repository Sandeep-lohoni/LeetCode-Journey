// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.


// Constraints:

// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(pair<int,char> ch1, pair<int,char> ch2){
        return ch1.first > ch2.first;
    }
    string frequencySort(string s) {
        vector<pair<int,char>> arr(123);
        for(auto ch : s){
            int freq = arr[ch].first;
            arr[ch] = {freq+1, ch};
        }
        sort(arr.begin(), arr.end(), comp);
        string ans = "";
        for(int i=0;i<123;++i){
            if(arr[i].first > 0){
                int freq = arr[i].first;
                char ch = arr[i].second;
                while(freq--) ans+=ch; 
            }
        }
        return ans;

    }
};
