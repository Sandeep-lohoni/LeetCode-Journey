// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree.There is no restriction on how your serialization /
// deserialization algorithm should work.You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification : The input /
// output format is the same as how LeetCode serializes a binary tree.You do not necessarily need to follow this format,
// so please be creative and come up with different approaches yourself.

// Example 1 :

// Input : root = [ 1, 2, 3, null, null, 4, 5 ] Output : [ 1, 2, 3, null, null, 4, 5 ] Example 2 :

// Input : root = [] Output : []

// Constraints :

// The number of nodes in the tree is in the range[0, 104]
//.- 1000 <= Node.val <= 1000

// solution

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current == NULL)
                ans += "#,";
            else
                ans += (to_string(current->val) + ',');
            if (current != NULL)
            {
                q.push(current->left);
                q.push(current->right);
            }
        }
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                current->left == NULL;
            }
            else
            {
                TreeNode *leftnode = new TreeNode(stoi(str));
                current->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                current->right = NULL;
            }
            else
            {
                TreeNode *rightnode = new TreeNode(stoi(str));
                current->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};