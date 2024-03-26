// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int m=arr.size();
        int n=arr[0].size();
        int top=0,left=0,right=n-1,bottom=m-1;
        while(right>=left && bottom>=top){
            for( int i=left;i<=right;i++){
                ans.push_back(arr[top][i]);
            }
            top++;
        for( int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(bottom>=top){
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(right>=left){
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
        }
        return ans;
    }
};