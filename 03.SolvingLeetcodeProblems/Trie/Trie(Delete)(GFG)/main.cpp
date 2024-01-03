#include <iostream>
#include <cstring>
using namespace std;

const int ALPHABET_SIZE = 26;

struct trie_node_t
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];

    trie_node_t() : value(0)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Solution
{
public:
    void deleteKey(trie_node_t *root, char key[])
    {
        trie_node_t *current = root;
        int length = strlen(key);

        for (int i = 0; i < length; i++)
        {
            int index = key[i] - 'a';

            // Check if the current character exists in the Trie
            if (current->children[index] == nullptr)
            {
                // Key not found, nothing to delete
                return;
            }

            // Move to the next node
            current = current->children[index];
        }

        // If the key is a valid word in the Trie, mark it as not a leaf node
        if (current->value != 0)
        {
            current->value = 0;
        }
    }
};

//Time complexity : O(L), where L is the length of the key.
//Space complexity : O(1)