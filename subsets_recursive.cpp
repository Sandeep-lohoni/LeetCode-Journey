// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

// solution

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> sets;
   void generate(vector<int> sub, int i, vector<int>& nums){
            if(i==nums.size()){
                sets.push_back(sub);
                return;
            }
            generate(sub,i+1,nums);
            sub.push_back(nums[i]);
            generate(sub, i+1, nums);
            sub.pop_back();
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        generate(empty,0,nums);
        return sets;
    }
};