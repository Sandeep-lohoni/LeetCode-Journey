// You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

// Note :
// No need to return anything. You should sort the array in-place.
// For example :
// Let ‘ARR’ be: [1, 4, 2]
// The sorted array will be: [1, 2, 4].
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10
// 1 <= N <= 5*10^3
// 1 <= ARR[i] <= 10^5

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 4
// 3 1 2 2
// 3
// 1 4 2
// Sample Output 1 :
// 1 2 2 3
// 1 2 4
// Explanation For Sample Output 1 :
// For test case 1: 
// The sorted array will be: [1, 2, 2, 3].

// For test case 2: 
// The sorted array will be: [1, 2, 4].
// Sample Input 2 :
// 2
// 4
// 4 12 11 20
// 6
// 6 5 4 3 2 1
// Sample Output 2 :
// 4 11 12 20
// 1 2 3 4 5 6
// C++ (g++ 5.4)
// 1234567891011


// solution
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}