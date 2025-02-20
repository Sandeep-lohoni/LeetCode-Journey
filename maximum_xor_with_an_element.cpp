// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

// Example 1:

// Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
// Output: [3,3,7]
// Explanation:
// 1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
// 2) 1 XOR 2 = 3.
// 3) 5 XOR 2 = 7.
// Example 2:

// Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
// Output: [15,-1,5]

// solution
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    // Array to store links
    // to child nodes (0 and 1)
    Node *links[2];

    // Method to check if a specific
    // bit key is present in the child nodes
    bool containsKey(int bit)
    {

        // Returns true if the link at
        // index 'bit' is not NULL
        return (links[bit] != NULL);
    }

    // Method to get the child node
    // corresponding to a specific bit
    Node *get(int bit)
    {

        // Returns the child
        // node at index 'bit'
        return links[bit];
    }

    // Method to set a child node at a
    // specific index in the links array
    void put(int bit, Node *node)
    {

        // Sets the child node at index
        // 'bit' to the provided node
        links[bit] = node;
    }
};

// Trie class
class Trie
{
private:
    // Root node of the Trie
    Node *root;

public:
    // Constructor to initialize
    // the Trie with a root node
    Trie()
    {
        // Creates a new root
        // node for the Trie
        root = new Node();
    }

    // Method to insert a number into the Trie
    void insert(int num)
    {
        // Start from the root node
        Node *node = root;
        // Iterate through each bit of the
        // number (from left to right)
        for (int i = 31; i >= 0; i--)
        {
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1;

            // If the current node doesn't have a
            // child node with the current bit
            if (!node->containsKey(bit))
            {

                // Create a new child node
                // with the current bit
                node->put(bit, new Node());
            }

            // Move to the child node
            // corresponding to the current bit
            node = node->get(bit);
        }
    }

    // Method to find the maximum
    // XOR value for a given number
    int getMax(int num)
    {
        // Start from the root node
        Node *node = root;

        // Initialize the maximum XOR value
        int maxNum = 0;

        // Iterate through each bit of
        // the number (from left to right)
        for (int i = 31; i >= 0; i--)
        {

            // Extract the i-th
            // bit of the number
            int bit = (num >> i) & 1;

            // If the complement of the current
            // bit exists in the Trie
            if (node->containsKey(1 - bit))
            {

                // Update the maximum XOR
                // value with the current bit
                maxNum |= (1 << i);

                // Move to the child node corresponding
                // to the complement of the current bit
                node = node->get(1 - bit);
            }
            else
            {

                // Move to the child node
                // corresponding to the current bit
                node = node->get(bit);
            }
        }

        // Return the maximum XOR value
        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &queries)
    {
        // Initialize vector to
        // store results of queries
        vector<int> ans(queries.size(), 0);

        // Vector to store offline queries
        vector<pair<int, pair<int, int>>> offlineQueries;
        // Sort the array of numbers
        sort(arr.begin(), arr.end());

        int index = 0;

        // Convert queries to offline
        // queries and store them in a vector
        for (auto &it : queries)
        {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort offline queries
        // based on their end points
        sort(offlineQueries.begin(), offlineQueries.end());

        // Pointer to iterate through
        // the array of numbers
        int i = 0;

        // Number of elements in the array
        int n = arr.size();

        // Create an instance of
        // the Trie data structure
        Trie trie;

        // Process each offline query
        for (auto &it : offlineQueries)
        {
            // Insert numbers into the trie
            // until the current query's end point
            while (i < n && arr[i] <= it.first)
            {
                trie.insert(arr[i]);
                i++;
            }

            // If there are numbers inserted
            // into the trie, find the maximum
            // XOR value for the query range
            if (i != 0)
                ans[it.second.second] = trie.getMax(it.second.first);
            else
                // If no numbers inserted,
                // set result to -1
                ans[it.second.second] = -1;
        }
        // Return the results
        // of all queries
        return ans;
    }
};