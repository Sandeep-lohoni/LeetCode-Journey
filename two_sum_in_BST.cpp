// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// Example 1 :

// Input : root = [ 5, 3, 6, 2, 4, null, 7 ],
// k = 9 Output : true Example 2 :

// Input : root = [ 5, 3, 6, 2, 4, null, 7 ],
// k = 28 Output : false

// Constraints :

// The number of nodes in the tree is in the range[1, 104]
//.- 104 <=
// Node.val <= 104 root is guaranteed to be a valid binary search tree.- 105 <= k <= 105

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

class BSTIterator
{
    stack<TreeNode *> st;
    // reverse->true = before
    // reverse->false = next
    bool reverse = true;

private:
    void pushAll(TreeNode *node, bool reverse)
    {
        while (node != NULL)
        {
            st.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root, reverse);
    }
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        if (!reverse)
        {
            pushAll(node->right, reverse);
        }
        else
        {
            pushAll(node->left, reverse);
        }
        return node->val;
    }
    bool hasNext()
    {
        return !st.empty();
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator le(root, false);
        BSTIterator ri(root, true);
        int l = le.next();
        int r = ri.next();
        while (l < r)
        {
            if (l + r == k)
                return true;
            else if (l + r < k)
                l = le.next();
            else
                r = ri.next();
        }
        return false;
    }
};