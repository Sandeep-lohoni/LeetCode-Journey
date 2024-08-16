// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100

// solution
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool helper(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == NULL && node2 == NULL)
            return true;
        if (node1 == NULL || node2 == NULL)
            return false;
        if (node1->val != node2->val)
            return false;
        return (helper(node1->left, node2->right) && helper(node1->right, node2->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return (helper(root->left, root->right));
    }
};