// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char, string> mp={
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void helper(string & digits,vector<string>&ans, int ind, string output){
        if(ind>=digits.length()){
            ans.push_back(output);
            return;
        }
        string temp=mp[digits[ind]];
        for(int i=0;i<temp.length();++i){
            helper(digits,ans,ind+1,output+temp[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return {};
        }
        string output="";
        helper(digits,ans,0,output);
        return ans;
    }
};