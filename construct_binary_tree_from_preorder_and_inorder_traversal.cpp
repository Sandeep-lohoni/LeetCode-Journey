// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1 :

// Input : preorder = [ 3, 9, 20, 15, 7 ],
// inorder = [ 9, 3, 15, 20, 7 ] Output : [ 3, 9, 20, null, null, 15, 7 ] Example 2 :

// Input : preorder = [-1],
// inorder = [-1] Output : [-1]

// Constraints :

// 1 <= preorder.length <= 3000 inorder.length ==
// preorder.length - 3000 <= preorder[i],
// inorder[i] <= 3000 preorder and inorder consist of unique values.Each value of inorder also appears in preorder.preorder is guaranteed to be the preorder traversal of the tree.inorder is guaranteed to be the inorder traversal of the tree.

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
    TreeNode *buildNode(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> &mp)
    {
        if (prestart > preend || instart > inend)
            return NULL;
        TreeNode *root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int numsleft = inroot - instart;
        root->left = buildNode(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, mp);
        root->right = buildNode(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        int n = preorder.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = buildNode(preorder, 0, n - 1, inorder, 0, n - 1, mp);
        return root;
    }
};