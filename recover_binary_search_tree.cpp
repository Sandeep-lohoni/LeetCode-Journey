// You are given the root of a binary search tree(BST), where the values of exactly two nodes of the tree were swapped by mistake.Recover the tree without changing its structure.

// Input : root = [ 1, 3, null, null, 2 ] Output : [ 3, 1, null, null, 2 ] Explanation : 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.Example 2 :

// Input : root = [ 3, 1, 4, null, null, 2 ] Output : [ 2, 1, 4, null, null, 3 ] Explanation : 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

// Constraints :

// The number of nodes in the tree is in the range[2, 1000]
//.- 231 <= Node.val <= 231 - 1

// Follow up : A solution using O(n) space is pretty straight
//-
// forward.Could you devise a constant O(1) space solution
//?

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
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (prev != NULL && prev->val > curr->val)
                {
                    if (first == NULL)
                    {
                        first = prev;
                        middle = curr;
                    }
                    else
                    {
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
            else
            {
                TreeNode *predecessor = curr->left;
                while (predecessor->right != NULL && predecessor->right != curr)
                {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else
                {
                    predecessor->right = NULL;
                    if (prev != NULL && prev->val > curr->val)
                    {
                        if (first == NULL)
                        {
                            first = prev;
                            middle = curr;
                        }
                        else
                        {
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};