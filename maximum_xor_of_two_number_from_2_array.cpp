// Problem statement
//             You are given two arrays of non -
//         negative integers say ‘arr1’ and ‘arr2’.Your task is to find the maximum value of( ‘A’ xor ‘B’) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise
//     xor operation.

//             Detailed explanation(Input / output format, Notes, Images)
//                 Constraints : 1 <= T
//             <= 5 1 <= N,
//     M <= 1000 0 <= arr1[i], arr2[i] <= 10 ^ 9

//                                 Where 'T' denotes the number of test cases,
//     'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i] ', and ‘arr2[i]’ denotes the ' i - th' element of the first array and second array.

// Time limit : 1 sec
// Sample Input 1 : 1 7 7 6 6 0 6 8 5 6 1 7 1 7 8 0 2 Sample Output 1 : 15 Explanation of sample input 1 : First testcase : Possible pairs are(6, 7),
//      (6, 8), (6, 2), (8, 7), (8, 8), (6, 2).And 8 xor 7 will give the maximum result i.e.15 Sample Input 2 : 1 3 3 25 10 2 8 5 3 Sample Output 2 : 28 Explanation of sample input 2 : First test case:
//  28 is the maximum possible xor given by pair = (25, 5).It is the maximum possible xor among all possible pairs.

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

    int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
    {
        // Write your code here.
        Trie trie;
        for (auto &it : arr1)
        {
            trie.insert(it);
        }
        int ans = 0;
        for (auto &it : arr2)
        {
            ans = max(ans, trie.getMax(it));
        }
        return ans;
    }
};