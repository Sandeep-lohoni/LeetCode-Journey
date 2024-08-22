// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1 :

// Input : inorder = [ 9, 3, 15, 20, 7 ],
// postorder = [ 9, 15, 7, 20, 3 ] Output : [ 3, 9, 20, null, null, 15, 7 ] Example 2 :

// Input : inorder = [-1],
// postorder = [-1] Output : [-1]

// Constraints :

// 1 <= inorder.length <= 3000 postorder.length ==
// inorder.length - 3000 <= inorder[i],
// postorder[i] <= 3000 inorder and postorder consist of unique values.Each value of postorder also appears in inorder.inorder is guaranteed to be the inorder traversal of the tree.postorder is guaranteed to be the postorder traversal of the tree.

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
    TreeNode *buildNode(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend, map<int, int> &mp)
    {
        if (instart > inend || poststart > postend)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postend]);
        int inroot = mp[root->val];
        int numsleft = inroot - instart;
        root->left = buildNode(inorder, instart, inroot - 1, postorder, poststart, poststart + numsleft - 1, mp);
        root->right = buildNode(inorder, inroot + 1, inend, postorder, poststart + numsleft, postend - 1, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = buildNode(inorder, 0, n - 1, postorder, 0, n - 1, mp);
        return root;
    }
};