// A trie(pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class :

//     Trie() Initializes the trie object.void insert(String word) Inserts the string word into the trie.boolean search(String word) Returns true if the string word is in the trie(i.e., was inserted before),
//     and false otherwise.boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

// Example 1 :

//     Input["Trie", "insert", "search", "search", "startsWith", "insert", "search"][[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]] Output[null, null, true, false, true, null, true]

//     Explanation Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app"); // return True

// solution

#include <bits/stdc++.h>
using namespace std;
// Node structure for Trie
struct Node
{
    // Array to store links to child nodes, each index represents a letter
    Node *links[26];
    // Flag indicating if the node marks the end of a word
    bool flag = false;
    // Check if the node contains a specific key (letter)
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific key (letter) from the Trie
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Set the current node as the end of a word
    void setEnd()
    {
        flag = true;
    }

    // Check if the current node marks the end of a word
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // Create a new node for  letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                // If a letter is not found, there is no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        return true;
    }
};