// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17
 

// Constraints:

// 1 <= s.length <= 500
// s consists of only lowercase English letters.

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beauty(vector<int>& arr){
       int mf=-1;
       int lf=1e9;
       for(int i=0;i<26;++i){
        mf=max(mf,arr[i]);
        if(arr[i]>=1){
            lf=min(lf,arr[i]);
        }
       }
       return mf-lf;   
    }
    int beautySum(string s) {
        int rel=0;
        for(int i=0;i<s.size();++i){
            vector<int> arr(26,0);
            for(int j=i;j<s.size();++j){
                arr[s[j]-'a']++;
                rel+=beauty(arr);
            }
        }
        return rel;
    }
};