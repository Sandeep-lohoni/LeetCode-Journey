// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.


// solution
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    bool ispalindrome(string str){
        int st=0;
        int end=str.size()-1;
       while(st<end){
            if(str[st++]!=str[end--]) return false;
        }
        return true;
    }
    void helper(string s,vector<vector<string>>&mp,vector<string>&rel,int ind){
        if(ind==s.size()){
            mp.push_back(rel);
            return;
        }
        for(int i=ind;i<s.size();++i){
            if(ispalindrome(s.substr(ind,i-ind+1))){
                rel.push_back(s.substr(ind,i-ind+1));
                helper(s,mp,rel,i+1);
                rel.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> mp;
        vector<string> rel;
        helper(s,mp,rel,0);
        return mp;
    }
};
