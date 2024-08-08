// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:

// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]

// Constraints:

// The number of the nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        TreeNode *temp = NULL;
        TreeNode *curr = root;
        stack<TreeNode *> st;
        vector<int> ans;
        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};