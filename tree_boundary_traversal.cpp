// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

// Example 1:

// Input:
//         1
//       /   \
//      2     3
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9

// Output: 1 2 4 8 9 6 7 3
// Explanation:

// Example 2:

// Input:
//             1
//            /
//           2
//         /  \
//        4    9
//      /  \    \
//     6    5    3
//              /  \
//             7     8

// Output: 1 2 4 6 5 7 8
// Explanation:

// As you can see we have not taken the right subtree.
// Your Task:
// This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

// solution

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class Solution
{
public:
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    void leftBoundaryNode(Node *root, vector<int> &ans)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                ans.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void leafNode(Node *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->data);
        }
        if (root->left)
            leafNode(root->left, ans);
        if (root->right)
            leafNode(root->right, ans);
    }
    void reverseRightBoundaryNode(Node *root, vector<int> &ans)
    {
        vector<int> res;
        Node *curr = root->right;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = res.size() - 1; i >= 0; --i)
        {
            ans.push_back(res[i]);
        }
    }
    vector<int> boundary(Node *root)
    {

        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->data);
        leftBoundaryNode(root, ans);
        leafNode(root, ans);
        reverseRightBoundaryNode(root, ans);
        return ans;
    }
};