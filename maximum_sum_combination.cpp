// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid sum combinations from all the possible sum combinations.

// Note : Output array must be sorted in non-increasing order.

// Example 1:

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation:
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
// Example 2:

// Input:
// N = 4
// K = 3
// A [ ] = {1, 4, 2, 3}
// B [ ] = {2, 5, 1, 6}
// Output: {10, 9, 9}
// Explanation:
// 10 -> (A : 4) + (B : 6)
// 9 -> (A : 4) + (B : 5)
// 9 -> (A : 3) + (B : 6)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

// Expected Time Complexity: O(Nlog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤  105
// 1 ≤ K ≤  N
// 1 ≤ A [ i ] , B [ i ] ≤ 104

// solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxCombinations(int n, int K, vector<int> &A, vector<int> &B)
    {
        // code here
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        pq.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));
        st.insert(make_pair(n - 1, n - 1));
        for (int cnt = 0; cnt < K; ++cnt)
        {
            pair<int, pair<int, int>> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            int i = temp.second.first;
            int j = temp.second.second;
            if (i - 1 >= 0)
            {
                int sum = A[i - 1] + B[j];
                pair<int, int> temp1 = make_pair(i - 1, j);
                if (st.find(temp1) == st.end())
                {
                    pq.push(make_pair(sum, temp1));
                    st.insert(temp1);
                }
            }
            if (j - 1 >= 0)
            {
                int sum = A[i] + B[j - 1];
                pair<int, int> temp1 = make_pair(i, j - 1);
                if (st.find(temp1) == st.end())
                {
                    pq.push(make_pair(sum, temp1));
                    st.insert(temp1);
                }
            }
        }
        return ans;
    }
};