// You are given an array arr of N integers representing a min Heap. The task is to convert it to max Heap.

// A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node.

// Example 1:

// Input:
// N = 4
// arr = [1, 2, 3, 4]
// Output:
// [4, 2, 3, 1]
// Explanation:

// The given min Heap:

//           1
//         /   \
//       2       3
//      /
//    4

// Max Heap after conversion:

//          4
//        /   \
//       2     3
//     /
//    1
// Example 2:

// Input:
// N = 5
// arr = [3, 4, 8, 11, 13]
// Output:
// [13, 11, 8, 3, 4]
// Explanation:

// The given min Heap:

//           3
//         /   \
//       4      8
//     /   \ 
//   11     13

// Max Heap after conversion:

//           13
//         /    \
//       11      8
//     /   \ 
//    3     4

// Your Task:
// Complete the function int convertMinToMaxHeap(), which takes integer N and array represented minheap as input and converts it to the array representing maxheap. You don't need to return or print anything, modify the original array itself.

// Note: Only an unique solution is possible under the expected time complexity.

// Expected Time Complexity: O(N * log N)
// Expected Auxiliary Space: O(N)

// Constraints:

// 1 <= N <= 105
// 1 <= arr[i] <= 109

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        for (int i = (N / 2) - 1; i >= 0; --i)
        {
            heapify(arr, N, i);
        }
    }
    void heapify(vector<int> &arr, int n, int i)
    {
        while (true)
        {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;
            if (largest != i)
            {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
                break;
        }
    }
};