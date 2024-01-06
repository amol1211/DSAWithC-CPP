//421. Maximum XOR of Two Numbers in an Array
#include <iostream>
#include <vector>
#include <valarray>
using namespace std;

class Solution {
public:
    // Definition of a Trie Node
    struct trieNode {
        trieNode* left;  // Pointer for the 0 bit
        trieNode* right; // Pointer for the 1 bit
    };

    // Function to insert a number into the Trie
    void insert(trieNode* root, int &num) {
        trieNode* current = root;

        // Iterate over each bit of the number
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1; // Extract the i-th bit from the number

            // If the bit is 0, go left in the Trie; otherwise, go right
            if (ith_bit == 0) {
                if (current->left == nullptr) {
                    current->left = new trieNode();  // Create a new node if it doesn't exist
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new trieNode(); // Create a new node if it doesn't exist
                }
                current = current->right;
            }
        }
    }

    // Function to find the maximum XOR with a number in the Trie
    int findMaxXor(trieNode* root, int &num) {
        int maxXor = 0;
        trieNode* crawl = root;

        // Iterate over each bit of the number
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1; // Extract the i-th bit from the number

            // If the bit is 1, try to find a 0 bit in the Trie; otherwise, try to find a 1 bit
            if (ith_bit == 1) {
                if (crawl->left != nullptr) {
                    maxXor += pow(2, i); // Calculating XOR value on the fly
                    crawl = crawl->left;
                } else {
                    crawl = crawl->right;
                }
            } else {
                if (crawl->right != nullptr) {
                    maxXor += pow(2, i); // Calculating XOR value on the fly
                    crawl = crawl->right;
                } else {
                    crawl = crawl->left;
                }
            }
        }

        return maxXor;
    }

    // Function to find the maximum XOR among all pairs of numbers in the vector
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode(); // Initialize the Trie

        // Insert all numbers into the Trie
        for (int &num : nums) {
            insert(root, num);
        }

        int maxResult = 0;

        // Find the maximum XOR for each number in the vector
        for (int i = 0; i < nums.size(); i++) {
            int temp = findMaxXor(root, nums[i]);

            maxResult = max(maxResult, temp);
        }

        return maxResult;
    }
};
