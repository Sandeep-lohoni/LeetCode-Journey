// Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree, the output should be 5 10 4 14 25.

// Examples :

// Input:
//        1
//      /   \
//     3     2
// Output: 3 1 2
// Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

// Thus bottom view of the binary tree will be 3 1 2.
// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 40 20 60 30
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Data of a node <= 105

// solution

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> todo;
        todo.push({root, 0});
        while (!todo.empty())
        {
            auto it = todo.front();
            todo.pop();
            Node *node = it.first;
            int line = it.second;
            mp[line] = node->data;
            if (node->left != NULL)
            {
                todo.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                todo.push({node->right, line + 1});
            }
        }
        for (auto p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};