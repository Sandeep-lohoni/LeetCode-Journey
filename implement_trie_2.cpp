// Problem statement
// Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

// 1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

// 2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

// 3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

// 4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// 5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
// Note:

// 1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

// 2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
// Can you help Ninja implement the "TRIE" data structure?

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= “T” <= 50
// 1 <= “N” <= 10000
//  “WORD” = {a to z}
// 1 <= | “WORD” | <= 1000

// Where “T” is the number of test cases, “N” denotes how many times the functions(as discussed above) we call, “WORD” denotes the string on which we have to perform all the operations as we discussed above, and | “WORD” | denotes the length of the string “WORD”.

// Time limit: 1 sec.
// Sample Input 1:
// 1
// 5
// insert coding
// insert ninja
// countWordsEqualTo coding
// countWordsStartingWith nin
// erase coding
// Sample Output 1:
// 1
// 1   
// Explanation of sample input 1:
// After insertion of “coding” in “TRIE”:

// After insertion of “ninja” in “TRIE”:

// Count words equal to “coding” :

// Count words those prefix is “nin”:

// After deletion of the word “coding”, “TRIE” is:

// Sample Input 2:
// 1
// 6
// insert samsung
// insert samsung
// insert vivo
// erase vivo
// countWordsEqualTo samsung
// countWordsStartingWith vi
// Sample Output 2:
// 2
// 0
// Explanation for sample input 2:
// insert “samsung”: we are going to insert the word “samsung” into the “TRIE”.

// insert “samsung”: we are going to insert another “samsung” word into the “TRIE”.

// insert “vivo”: we are going to insert the word “vivo” into the “TRIE”.

// erase “vivo”: we are going to delete the word “vivo” from the “TRIE”.

// countWordsEqualTo “samsung”: There are two instances of “sumsung” is present in “TRIE”.

// countWordsStartingWith “vi”: There is not a single word in the “TRIE” that starts from the prefix “vi”.

// solution

#include <bits/stdc++.h>

using namespace std;

// Define a struct for each node in the trie
struct Node
{
    // Array to store links to child nodes
    Node *links[26];
    // Counter for number of words that end at this node
    int cntEndWith = 0;
    // Counter for number of words that have this node as a prefix
    int cntPrefix = 0;

    // Function to check if the node contains a specific key
    bool containsKey(char ch)
    {
        // Check if the link corresponding to the character exists
        return (links[ch - 'a'] != NULL);
    }

    // Function to get the child node corresponding to a key
    Node *get(char ch)
    {
        // Return the link corresponding to the character
        return links[ch - 'a'];
    }

    // Function to insert a child node with a specific key
    void put(char ch, Node *node)
    {
        // Set the link corresponding to the character to the provided node
        links[ch - 'a'] = node;
    }

    // Function to increment the count of words that end at this node
    void increaseEnd()
    {
        // Increment the counter
        cntEndWith++;
    }

    // Function to increment the count of words that have this node as a prefix
    void increasePrefix()
    {
        // Increment the counter
        cntPrefix++;
    }

    // Function to decrement the count of words that end at this node
    void deleteEnd()
    {
        // Decrement the counter
        cntEndWith--;
    }

    // Function to decrement the count of words that have this node as a prefix
    void reducePrefix()
    {
        // Decrement the counter
        cntPrefix--;
    }
};

// Define a class for the trie data structure
class Trie
{
private:
    // Pointer to the root node of the trie
    Node *root;

public:
    // Constructor to initialize the trie with an empty root node
    Trie()
    {
        // Create a new root node
        root = new Node();
    }

    // Function to insert a word into the trie
    void insert(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is not already in the trie
            if (!node->containsKey(word[i]))
            {
                // Create a new node for the character
                node->put(word[i], new Node());
            }
            // Move to the child node corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix count for the node
            node->increasePrefix();
        }
        // Increment the end count for the last node of the word
        node->increaseEnd();
    }

    // Function to count the number of words equal to a given word
    int countWordsEqualTo(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
            }
            else
            {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Return the count of words ending at the node
        return node->cntEndWith;
    }
    // Function to count the number of words starting with a given prefix
    int countWordsStartingWith(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
            }
            else
            {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Return the count of words with the prefix
        return node->cntPrefix;
    }

    // Function to erase a word from the trie
    void erase(string word)
    {
        // Start from the root node
        Node *node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++)
        {
            // If the character is found in the trie
            if (node->containsKey(word[i]))
            {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix count for the node
                node->reducePrefix();
            }
            else
            {
                // Return if the character is not found
                return;
            }
        }
        // Decrement the end count for the last node of the word
        node->deleteEnd();
    }
};