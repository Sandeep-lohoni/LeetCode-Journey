// Given a binary tree and a node data called target.Find the minimum time required to burn the complete binary tree if the target is set on fire.It is known that in 1 second all nodes connected to a given node get burned.That is its left child, right child, and parent.Note : The tree contains unique values.

// Examples :

//Input : 1 / 2 3 /  \ 4 5 6 / \ 7 8 9

// 10 Target Node = 8 Output : 7 Explanation : If leaf with the value 8 is set on fire.After 1 sec : 5 is set on fire.After 2 sec : 2,
// 7 are set to fire.After 3 sec : 4, 1 are set to fire.After 4 sec : 3 is set to fire.After 5 sec : 6 is set to fire.After 6 sec : 9 is set to fire.After 7 sec : 10 is set to fire.It takes 7s to burn the complete tree.Input : 1 / 2 3 /  \ 4 5 7 / / 8 10 Target Node = 10 Output : 5

// Expected Time Complexity : O(number of nodes) Expected Auxiliary Space : O(height of tree)

// Constraints : 1 ≤ number of nodes ≤ 105

// 1 ≤ values of nodes ≤ 105

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
class Solution
{
    void markParent(Node *root, unordered_map<Node *, Node *> &parent_track, int target, Node *&point)
    {
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            Node *current = queue.front();
            queue.pop();
            if (current->left)
            {
                parent_track[current->left] = current;
                queue.push(current->left);
                if (current->left->data == target)
                    point = current->left;
            }
            if (current->right)
            {
                parent_track[current->right] = current;
                queue.push(current->right);
                if (current->right->data == target)
                    point = current->right;
            }
        }
    }

public:
    int minTime(Node *root, int target)
    {
        // Your code goes here
        unordered_map<Node *, Node *> parent_track;
        Node *point = NULL;
        if (root->data == target)
        {
            point = root;
        }
        markParent(root, parent_track, target, point);
        unordered_map<Node *, bool> visited;
        queue<Node *> q;
        q.push(point);
        visited[point] = true;
        int cnt = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; ++i)
            {
                Node *current = q.front();
                q.pop();
                if (current->left && !visited[current->left])
                {
                    visited[current->left] = true;
                    q.push(current->left);
                    flag = true;
                }
                if (current->right && !visited[current->right])
                {
                    visited[current->right] = true;
                    q.push(current->right);
                    flag = true;
                }
                if (parent_track[current] && !visited[parent_track[current]])
                {
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                    flag = true;
                }
            }
            if (flag)
                cnt++;
        }
        return cnt;
    }
};