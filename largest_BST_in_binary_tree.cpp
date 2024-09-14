// Given a binary tree.Find the size of its largest subtree which is a Binary Search Tree.Note : Here Size equals the number of nodes in the subtree.

// Examples :

// Input : 1 /
// 4 4 / \ 
//6 8 Output : 1 Explanation : There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

// Input : 6 /
// 6 2
//\ /
// 2 1 3 Output : 3 Explanation : The following sub -
// tree is a BST of size 3 : 2 /
// 1 3 Expected Time Complexity : O(n).Expected Auxiliary Space : O(Height of the BST).

// Constraints : 1 ≤ Number of nodes ≤ 105 1 ≤ Data of a node ≤ 106

// solution

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Nodevalue
{
public:
    int maxvalue, minvalue, maxsize;
    Nodevalue(int minvalue, int maxvalue, int maxsize)
    {
        this->maxvalue = maxvalue;
        this->minvalue = minvalue;
        this->maxsize = maxsize;
    }
};

Nodevalue helper(Node *root)
{
    if (!root)
    {
        return Nodevalue(INT_MAX, INT_MIN, 0);
    }
    auto left = helper(root->left);
    auto right = helper(root->right);

    if (left.maxvalue < root->data && root->data < right.minvalue)
    {
        return Nodevalue(min(left.minvalue, root->data), max(right.maxvalue, root->data), left.maxsize + right.maxsize + 1);
    }
    return Nodevalue(INT_MIN, INT_MAX, max(left.maxsize, right.maxsize));
}

class Solution
{
public:
    int largestBst(Node *root)
    {
        // Your code here
        return helper(root).maxsize;
    }
};