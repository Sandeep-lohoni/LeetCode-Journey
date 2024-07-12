// Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).

// Examples :

// Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
// Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
// Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
// Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
// Expected Time Complexity: O(k2*Log(k))
// Expected Auxiliary Space: O(k2)

// Constraints:
// 1 <= k <= 100

// solution

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return (a->data > b->data);
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<node *, vector<node *>, compare> minheap;
        for (int i = 0; i < k; ++i)
        {
            node *temp = new node(arr[i][0], i, 0);
            minheap.push(temp);
        }
        vector<int> ans;
        while (minheap.size() > 0)
        {
            node *temp = minheap.top();
            ans.push_back(temp->data);
            minheap.pop();
            int i = temp->i;
            int j = temp->j;
            if (j + 1 < arr[i].size())
            {
                node *next = new node(arr[i][j + 1], i, j + 1);
                minheap.push(next);
            }
        }
        return ans;
    }
};